#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>


void DrawMap();//打印地图

POINT GetPlayerPosition();//获取玩家位置

void Import();//输入

void Up();//上

void Down();//下

void Left();//左

void Right();//右

int GetSpareBox();//获取空箱子个数

int cas;//关卡