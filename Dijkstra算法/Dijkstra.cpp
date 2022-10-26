/*!
* Copyright (c) 2020,ZYF.
* All Rights Reserved.
*
* \file Dijkstra.cpp
* \brief 迪杰斯特拉算法
*
* \author ZYF
* \date 2020/6/30 18:30:42
* \version 1.0.0
*/

#include <iostream>

/** 邻接矩阵行列的最大数 */
const int g_nMaxNumber = 100;

/** 最大整数（代表无穷大） */
const int g_nMaxInt = 999999;

/*!
* \brief 迪杰斯特拉算法
* \param nNodes : int 顶点总数
* \param nV : int 源点
* \param pDist : int * 当前点到源点的最短距离
* \param pPrev : int * 当前点的前一节点
* \param matrixDistance : int 两点间的距离（邻接矩阵）
* \returns void :
* \throws <exception class>
* \remarks
* \see
*/
void Dijkstra(int nNodes, int nV, int* pDist, int* pPrev, int matrixDistance[g_nMaxNumber][g_nMaxNumber])
{
	/*
	算法描述：
		迪杰斯特拉算法(Dijkstra)是由荷兰计算机科学家狄克斯特拉于1959 年提出的，因此又叫狄克斯特拉算法。
		是从一个顶点到其余各顶点的最短路径算法，解决的是有权图中最短路径问题。
		迪杰斯特拉算法主要特点是以起始点为中心向外层层扩展，直到扩展到终点为止。

	算法逻辑：
		1. 初始化两个集合，S集合和V集合。
			S集合初始只有源顶点即顶点A，
			V集合初始为除了源顶点以外的其他所有顶点，
			dist字典值都为-1；
			紧接着，根据邻接矩阵，找出与A存在边的顶点list，
			遍历list，依次更新dist字典（比如list={B,C}，则依次更新字典键为B,C 的距离值）,
			求出与 A 距离最近的顶点，并从V集合中移除到S集合中；
		2. 抓出S集合的最后一个元素，根据邻接矩阵，找出V集合中与之存在边的顶点list，
		遍历list，求出与之距离最小的顶点，并从V集合中移除到S集合中。
		3 dist更新，分情况讨论，
			3.1如果遍历到的顶点不是与之最小的顶点，则直接更新dist字典，比如list={D,E}，则依次更新字典键为D,E的距离值，
			3.2如果遍历到的顶点是与之最小的顶点，则需要判断dist[此顶点]与当前的距离，如果后者小，才更新dist[此顶点]，否则不更新。
		4. 重复2和3，直到V集合元素为空为止。
	*/

	bool bArr[g_nMaxNumber];//判断是否放到集合S中（true:已使用;false:未使用）标记数组，标记顶点是否已经被选择过
	for (int i = 1; i <= nNodes; i++)
	{
		pDist[i] = matrixDistance[nV][i];
		bArr[i] = false;

		if (pDist[i] == g_nMaxInt)
			pPrev[i] = 0;
		else
			pPrev[i] = nV;
	}

	pDist[nV] = 0;
	bArr[nV] = true;

	//依次将未放入S集合的结点中，取pDist[]最小值的结点，放入结合S中
	//一旦S包含了所有V中顶点，pDist就记录了从源点到所有其他顶点之间的最短路径长度
	//注意是从第二个节点开始，第一个为源点

	int nTmp = 0;//临时,找最小距离使用
	int nIndex = 0;//最小距离的索引
	for (int i = 2; i <= nNodes; i++)
	{
		nTmp = g_nMaxInt;
		nIndex = nV;

		//找出当前未使用的点j的最短距离pDist[j]
		for (int j = 1; j < nNodes; j++)
		{
			if (!bArr[j] && pDist[j] < nTmp)
			{
				nIndex = j;
				nTmp = pDist[j];
			}
		}

		bArr[nIndex] = true;

		//更新当前点到源点的最短距离pDist
		for (int k = 1; k <= nNodes; k++)
		{
			if (!bArr[k] && matrixDistance[nIndex][k] < g_nMaxInt)
			{
				nTmp = pDist[nIndex] + matrixDistance[nIndex][k];
				if (nTmp < pDist[k])
				{
					pDist[k] = nTmp;
					pPrev[k] = nIndex;
				}
			}
		}
	}
}

/*!
* \brief 查找并输出起点到终点的路径
* \param pPrev : int * 当前点的前一节点
* \param nStart : int 起点
* \param nEnd : int 终点
* \returns void :
* \throws <exception class>
* \remarks 第1个点到第5个点的最短路径输出形式形如“1 -> 4 -> 3 -> 5”
* \see
*/
void SearchPath(int* pPrev, int nStart, int nEnd)
{
	int nArr[g_nMaxNumber];
	int nIndex = 1;
	nArr[nIndex] = nEnd;
	nIndex++;
	int nTmp = pPrev[nEnd];
	while (nTmp != nStart)
	{
		nArr[nIndex] = nTmp;
		nIndex++;
		nTmp = pPrev[nTmp];
	}

	nArr[nIndex] = nStart;
	for (int i = nIndex; i >= 1; i--)
	{
		if (i != 1)
			std::cout << nArr[i] << " -> ";
		else
			std::cout << nArr[i] << std::endl;
	}
}

int main(int argc, char* argv[])
{
	//假设输入的数据如下（1-5个共5个点，7条边）
	//起点 终点 路径长度
	//1 2 10
	//1 4 30
	//1 5 100
	//2 3 50
	//3 5 10
	//4 3 20
	//4 5 60

	int nNodes = 5;//节点数量
	int matrixDistance[g_nMaxNumber][g_nMaxNumber];//两点间的距离

	//初始化邻接矩阵
	matrixDistance[0][0] = g_nMaxInt;
	matrixDistance[0][1] = g_nMaxInt;
	matrixDistance[0][2] = g_nMaxInt;
	matrixDistance[0][3] = g_nMaxInt;
	matrixDistance[0][4] = g_nMaxInt;
	matrixDistance[0][5] = g_nMaxInt;
	matrixDistance[0][0] = g_nMaxInt;

	matrixDistance[1][1] = g_nMaxInt;
	matrixDistance[1][2] = 10;
	matrixDistance[1][3] = g_nMaxInt;
	matrixDistance[1][4] = 30;
	matrixDistance[1][5] = 100;

	matrixDistance[2][0] = g_nMaxInt;
	matrixDistance[2][1] = g_nMaxInt;
	matrixDistance[2][2] = g_nMaxInt;
	matrixDistance[2][3] = 50;
	matrixDistance[2][4] = g_nMaxInt;
	matrixDistance[2][5] = g_nMaxInt;

	matrixDistance[3][0] = g_nMaxInt;
	matrixDistance[3][1] = g_nMaxInt;
	matrixDistance[3][2] = g_nMaxInt;
	matrixDistance[3][3] = g_nMaxInt;
	matrixDistance[3][4] = g_nMaxInt;
	matrixDistance[3][5] = 10;

	matrixDistance[4][0] = g_nMaxInt;
	matrixDistance[4][1] = g_nMaxInt;
	matrixDistance[4][2] = g_nMaxInt;
	matrixDistance[4][3] = 20;
	matrixDistance[4][4] = g_nMaxInt;
	matrixDistance[4][5] = 60;

	int nArrPre[6];
	int nArrDist[6];
	for (int i = 0; i <= nNodes; i++)
	{
		nArrPre[i] = g_nMaxInt;
		nArrDist[i] = g_nMaxInt;
	}

	std::cout << "邻接矩阵:" << std::endl;
	for (int j = 1; j <= nNodes; j++)
	{
		for (int k = 1; k <= nNodes; k++)
			std::cout << matrixDistance[j][k] << std::endl;
	}

	Dijkstra(nNodes, 1, nArrDist, nArrPre, matrixDistance);
	std::cout << "\n第1个点到第2点的最短距离:" << nArrDist[2] << std::endl;
	std::cout << "第1个点到第2点的最短路径:";
	SearchPath(nArrPre, 1, 2);

	std::cout << "\n第1个点到第3点的最短距离:" << nArrDist[3] << std::endl;
	std::cout << "第1个点到第3点的最短路径:";
	SearchPath(nArrPre, 1, 3);

	std::cout << "\n第1个点到第4点的最短距离:" << nArrDist[4] << std::endl;
	std::cout << "第1个点到第4点的最短路径:";
	SearchPath(nArrPre, 1, 4);

	std::cout << "\n第1个点到第5点的最短距离:" << nArrDist[5] << std::endl;
	std::cout << "第1个点到第5点的最短路径:";
	SearchPath(nArrPre, 1, 5);

	return 1;
}
