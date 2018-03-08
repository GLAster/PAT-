/*
分析：对于前序和中序，或者后序和中序，可以唯一确定一棵二叉树，而对于前序和后序，可能不能唯一确定一棵二叉树，原因在于，
前序和后序对于左右子树的划分可能是不确定的。并且这种不确定，只可能出现在具有单一子树的节点中，这是因为，建树过程中，将
该子树放在左边，或者右边，都是可以的，因为这两种方式都将产生相同的前序和后序序列。因此，判断其是否unique便依据于此：倘
若在一次递归建树中，位于前序序列的第二个元素（是第一个元素的子树根节点，左儿子或者右儿子），和后序序列中倒数第二个元素相
同，这意味者，对于根节点来说（前序第一个元素），其只有一个儿子（要么是左儿子，要么是右儿子），这将不是unique的。
*/
#include <bits/stdc++.h>
using namespace std;
int n,pre[32],pos[32];
bool isunique=1;
vector<int> ino;
void build(int preL,int preR,int posL,int posR)
{
	if(preL>preR) return;
	if(preL==preR){
		ino.push_back(pre[preL]);
		return;
	}
	int e=pre[preL+1],prex=preL+1,posx=posL;
	while(posx<posR&&e!=pos[posx]) ++prex,++posx;
	if(posx==posR-1) isunique=0;
	build(preL+1,prex,posL,posx);
	ino.push_back(pre[preL]);
	build(prex+1,preR,posx+1,posR-1);
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",&pre[i]);
	}
	for(int i=0;i<n;++i){
		scanf("%d",&pos[i]);
	}
	build(0,n-1,0,n-1);
	isunique?printf("Yes\n"):printf("No\n");
	for(int i=0;i<n;++i){
		i==n-1?printf("%d\n",ino[i]):printf("%d ",ino[i]);
	}
	return 0;
}
