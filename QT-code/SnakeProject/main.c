#include <stdio.h>
#include<Windows.h>
#include <time.h>
#include <conio.h>



enum Direction
{
    UP=119, DOWN = 115, LEFT=97, RIGHT=100
};

enum FoodType
{
    LEVELONE, LEVELTWO
};

typedef struct _pos
{
    int _x;
    int _y;
} Pos;

typedef struct _food
{
    Pos pos_;
    enum FoodType ft_;
} Food;

enum SnakeBodyType
{
    HEAD, BODY, TAIL
};

typedef struct _snake
{
    Pos pos_;
    enum SnakeBodyType sbt_;
    struct _snake *next;
} Snake;

void GenerateFood(Snake *snake, Food *food);
int isFoodOnSnake(Snake *snake, Food *food);

void initFood(Food *food)
{
    //食物的范围在1 - 14之间
    food->pos_._x = rand() % 14 + 1;
    food->pos_._y = (unsigned int)rand() % 14 + 1;
    food->ft_ = LEVELONE;
}

void initSnake(Snake **head, Food *food)
{
    (*head) = (Snake *)malloc(sizeof(Snake));

     do
    {
        // 3 - 12的空间
        (*head)->pos_._x = rand() % 10 + 3;
        (*head)->pos_._y = rand() % 10 + 3;
        (*head)->sbt_ = HEAD;
        (*head)->next = NULL;

    }while((*head)->pos_._x != food->pos_._x && (*head)->pos_._y != food->pos_._y);
}

int isSnakePart(Snake *snake, int i, int j, enum SnakeBodyType *type)
{
    while(snake)
    {
        if(snake->pos_._x == i && snake->pos_._y == j)
        {
            *type = snake->sbt_;
            return 1;
        }

        snake = snake->next;
    }

    return 0;
}

void initDirection(enum Direction *dir)
{
    switch (rand() % 4)
    {
        case 0:
            *dir = UP;
            break;
        case 1:
            *dir = DOWN;
            break;
        case 2:
            *dir = LEFT;
            break;
        case 3:
            *dir = RIGHT;
            break;
    }
}

int isMeetWall(Snake *snake)
{
    if(snake->pos_._x == 0 || snake->pos_._x == 15 || snake->pos_._y == 0 || snake->pos_._y == 15)
        return -1;

    return 0;
}
/*
 *  看蛇头部是否撞到自己的身体
 */
int isEatMyself(Snake *snake)
{
    Pos prePos = snake->pos_;
    while(snake->next)
    {
        if(snake->next->pos_._x == prePos._x && snake->next->pos_._y == prePos._y)
        {
            return -1;
        }

        snake = snake->next;
    }
    return 0;
}

int isFood(Snake *snake, Food *food)
{
    if(snake->pos_._x == food->pos_._x && snake->pos_._y == food->pos_._y)
        return -1;

    return 0;
}

void eatFood(Snake *snake, Food *food)
{
    //先定位到尾部
    while(snake->next)
        snake = snake->next;
    //采用尾插法
    Snake *node = (Snake *)malloc(sizeof(Snake));
    snake->next = node;
    node->next = NULL;

    if(snake->sbt_ == HEAD)
        node->sbt_ = TAIL;
    else
    {
        snake->sbt_ = BODY;
        node->sbt_ = TAIL;
    }

    GenerateFood(snake, food);
}

void GenerateFood(Snake *snake, Food *food)
{

    do
    {
        food->pos_._x = rand() % 14 + 1;
        food->pos_._y = rand() % 14 + 1;
        food->ft_ = LEVELTWO;

    }while(isFoodOnSnake(snake, food));
}

int isFoodOnSnake(Snake *snake, Food *food)
{
    while(snake)
    {
        if(snake->pos_._x == food->pos_._x && snake->pos_._y == food->pos_._y)
        {
            return -1;
        }

        snake = snake->next;
    }
    return 0;
}

int snakeMove(Snake *snake, enum Direction *dir, Food *food)
{
    /*
     *更新蛇的位置
    */
    Pos prePos = snake->pos_;

    switch(*dir)
    {
        case UP:
            snake->pos_._x--;
            break;
        case DOWN:
            snake->pos_._x++;
            break;
        case LEFT:
            snake->pos_._y--;
            break;
        case RIGHT:
            snake->pos_._y++;
            break;
    }

    //撞墙
    if(isMeetWall(snake))
        return -1;
    //吃到自己
    if(isEatMyself(snake))
        return -1;
    //吃到食物
    if(isFood(snake, food))
        eatFood(snake, food);

    //移动
    Pos curPos;
    while(snake->next)
    {
        curPos = snake->next->pos_;
        snake->next->pos_ = prePos;
        prePos = curPos;

        snake = snake->next;
    }

    return 0;
}

void getDirection(enum Direction *dir)
{
    enum Direction newDir;
    while(_kbhit())
    {
        newDir = _getch();
        if(newDir == UP || newDir == DOWN || newDir == LEFT || newDir == RIGHT)
            *dir = newDir;
    }
}

void flushScreen(Food *food, Snake *snake)
{

    enum SnakeBodyType type;
    for(int i = 0; i < 16; i++)
    {
        for(int j = 0; j < 16; j++  )
        {
            if(i == 0 || j == 0 || i == 15 || j == 15)
                printf(" #");
            else if(isSnakePart(snake, i, j, &type))
            {
                switch(type)
                {
                    case HEAD:
                        printf(" $");
                        break;
                    case BODY:
                        printf(" *");
                        break;
                    case TAIL:
                        printf(" ^");
                        break;
                }
            }
            else if(food->pos_._x == i && food->pos_._y == j)
                printf(" &");
            else
                printf("  ");
        }
        putchar(10);
    }
}

int main(int argc, char *argv[])
{
    srand((int)time(NULL));

    Food food;
    initFood(&food);

    Snake *snake;
    initSnake(&snake, &food);

    enum Direction dir;
    initDirection(&dir);

    while(1)
    {
        system("cls");

        getDirection(&dir); //非阻塞的获取方向  controller

        int result = snakeMove(snake, &dir, &food);  //链表的数据在发生变化 model
        if(result)
            break;

        flushScreen(&food, snake); //呈现链表的变化状态  view
        Sleep(800);
    }
    return 0;
}
