#include<stdio.h>
#include<stdlib.h>
#include"SgLinkList.h"

//创建单向链表
pNODE CreateSgLinkList(void) {
    int i,length,data;
    pNODE p_new=NULL,pTail=NULL;
    //创建头节点，头结点是第0个节点，后面的节点从1开始计数
    pNODE pHead=(pNODE) malloc(sizeof(NODE));

    if(NULL==pHead) {
        printf("内存分配失败！\n");
        exit(EXIT_FAILURE);
    }

    pHead->data=0;
    pHead->pNext=NULL;
    pTail=pHead;

    printf("请输入要创建链表的长度: ");
    scanf("%d",&length);

    for(i=1;i<length+1;i++) {
        p_new=(pNODE)malloc(sizeof(NODE));
        if(NULL==p_new) {
            printf("内存分配失败! \n");
            exit(EXIT_FAILURE);
        }

        printf("请输入第%d个节点的值: ",i);
        scanf("%d",&data);

        p_new->data=data;
        p_new->pNext=NULL;
        pTail->pNext=p_new;
        pTail=p_new;
    }
    return pHead;
}

//打印单向链表，不打印头结点的值
void TraverseSgLinkList(pNODE pHead) {
    pNODE pt=pHead->pNext;

    printf("打印链表: ");
    while(pt!=NULL) {
        printf("%d ",pt->data);
        pt=pt->pNext;
    }
    putchar('\n');
}

//判断链表是否为空
int IsEmptySgLinkList(pNODE pHead) {
    if(pHead->pNext==NULL) 
        return 1;
    else
        return 0;
}

//计算单向链表长度
int GetLengthSgLinkList(pNODE pHead) {
    int length=0;
    pNODE pt=pHead->pNext;

    while(pt!=NULL) {
        length++;
        pt=pt->pNext;
    }
    return length;
}

//向单向链表插入一个节点，位置从1开始，到链表长度加1结束
int InsertEleSgLinkList(pNODE pHead,int pos,int data) {
    pNODE pt=NULL,p_new=NULL;

    if(pos>0 && pos<GetLengthSgLinkList(pHead)+2) {
        p_new=(pNODE)malloc(sizeof(NODE));
        if(NULL==p_new) {
            printf("内存分配失败! \n");
            exit(EXIT_FAILURE);
        }
        p_new->data=data;
        
        while(1) {
            pos--;
            if(0==pos)
                break;
            pHead=pHead->pNext;
        }

        pt=pHead->pNext;
        pHead->pNext=p_new;
        p_new->pNext=pt;

        return 1;
    }
    else
        return 0;
}

//从单向链表中删除一个节点，位置从1开始，到链表长度结束
int DeleteEleSgLinkList(pNODE pHead,int pos) {
    pNODE pt=NULL;

    if(pos > 0 && pos <GetLengthSgLinkList(pHead)+1) {
        while(1) {
            pos--;
            if(0==pos) {
                break;
            }
            pHead=pHead->pNext;
        }

        pt=pHead->pNext->pNext;
        free(pHead->pNext);
        pHead->pNext=pt;

        return 1;
    }
    else 
        return 0;
}

//删除整个单向链表，释放内存
void FreeMemory(pNODE *ppHead) {
    pNODE pt=NULL;
    while(*ppHead!=NULL) {
        pt=(*ppHead)->pNext;
        free(*ppHead);
        *ppHead=pt;
    }
}