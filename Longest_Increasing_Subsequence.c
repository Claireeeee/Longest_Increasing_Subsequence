//
//  main.c
//  Dynamic_knapsack_problem
//
//  Created by Claire on 2018/6/4.
//  Copyright © 2018年 Claire. All rights reserved.

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define RANGE 10



int *random_array(int length,int range);                                        //产生一组随机数
int LIS(int *rawdata,int length);                                          //主函数
int insert_place(int *_end,int start,int end,int to_be_inserted);           //寻在插入位的函数    二分法


int main(void){
    int *rawdata=random_array(15, 10);
    for (int i=0; i<15; i++) {
        printf("%d,",rawdata[i]);
    }
    printf("\n");
    printf("result: %d\n",LIS(rawdata,15));
}





int *random_array(int length,int range){
    int *random_array=malloc(sizeof(int)*length);
    srand((unsigned)time(0));
    for (int i=0; i<length; i++) {
        random_array[i]=rand()%range+1;
    }
    return random_array;
}


int LIS(int *rawdata,int length){
    int *_end=malloc(sizeof(int)*(length+1));
    _end[1]=rawdata[0];
    int end_place=1;
    for (int i=1; i<length; i++) {
        if (rawdata[i]>_end[end_place]) {                      //往后开（其实可以包含在寻找插入位置的函数中）
            _end[++end_place]=rawdata[i];
        }
        else if(rawdata[i]==_end[end_place]);                    //重复就什么都不做
        else{
            int place=insert_place(_end,1, end_place, rawdata[i]);             //寻找插入位置并更新
            if (place!=-1) {
                _end[place]=rawdata[i];
            }
        }
    }
    /*printf("_end:");
     for (int i=1; i<=end_place; i++) {
     printf("%d  ",_end[i]);
     }*/
    return end_place;
}

int insert_place(int *_end,int start,int end,int to_be_inserted){
    
    if (start==end) {
        /*if (to_be_inserted>_end[start]) {
         return start+1;
         }
         else if(to_be_inserted==_end[start]){
         return -1;
         }
         else{*/
        return start;
        
    }
    /*else if (end-start==1) {                                     //只有相等一个base case就够了
     if (to_be_inserted>_end[end]) {
     return end+1;
     }
     else if(to_be_inserted<_end[start]){
     return start;
     }
     else if (to_be_inserted==_end[start]||to_be_inserted==_end[end]){
     return -1;
     }
     else{
     return end;
     }
     
     }*/
    else{
        int mid=(start+end)/2;
        /*if (to_be_inserted==_end[mid]) {
         return -1;
         }*/
        if(to_be_inserted<=_end[mid]){                                  //递归条件控制得好可以省下很多base case的判断
            return insert_place(_end,start,mid,to_be_inserted);
        }
        else{
            return insert_place(_end,mid+1, end,to_be_inserted);
        }
        
    }
}





//有一个很精简的，用的循环   真的很精简




int upper_bound(int arr[], int s, int e, int key)             //传递数组和起始位置
{
    int mid;                                                 //尾递归可以用循环实现
    if (arr[e] <= key)
        return e + 1;                                       //最初的位置判断
    while (s < e)
    {
        mid = s + (e - s) / 2;                         //一个更到mid+1，一个更到mid，因为等号在更s处取了
        if (arr[mid] <= key)
            s = mid + 1;
        else
            e = mid;
    }
    return s;
}

int LIS_(int d[], int n)
{
    int i = 0, len = 1,*end = malloc(sizeof(int) * (n + 1));
    end[1] = d[0]; //初始化：长度为1的LIS末尾为d[0]
    for (i = 1; i < n; i++)
    {
        int pos = upper_bound(end, 1, len, d[i]); //找到插入位置
        end[pos] = d[i];
        if (len < pos) //按需要更新LIS长度
            len = pos;
    }
    return len;
}

























