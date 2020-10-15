#include<bits/stdc++.h>
using namespace std;

int query(int* arr, int start, int end, int* tree, int treeNode, int left, int right){
    
    if(start > right || end < left){        //Completely outside the range
        return -1;
    }
    if(start >=left && end <= right){       //Completely inside the range
        return tree[treeNode];
    }
    //Partially inside and partially outside
    int mid = (start+end)/2;
    int ans1 = query(arr,start, mid, tree, 2*treeNode+1, left, right);
    int ans2 = query(arr,start, mid, tree, 2*treeNode+2, left, right);

    return min( ans1, ans2);
}

void update(int* arr,int start, int end, int* tree, int treeNode, int index, int item){
    
    if(start == end){
        arr[index] = item;
        tree[treeNode] = item;
        return;
    }
    int mid = (start+end)/2;
    if(index < mid){
        update(arr, start, mid, tree, 2*treeNode+1, index, item);
    }else{
        update(arr, mid+1, end, tree, 2*treeNode+2, index, item);
    }
    tree[treeNode] = min( tree[2*treeNode+1], tree[2*treeNode+2]);
}

void buildTree(int* arr, int start, int end, int* tree, int treeNode){
    
    if(start == end){
        tree[treeNode] = arr[start];
        cout << tree[treeNode] << " ";
        return;
    }
    int mid = (start+end)/2;
    buildTree(arr, start, mid, tree, 2*treeNode+1);
    buildTree(arr, mid+1, end, tree, 2*treeNode+2);
    
    tree[treeNode] = min( tree[2*treeNode+1], tree[2*treeNode+2]);
    cout << tree[treeNode] << " ";
}

int main(){
    
    int n,q;
    cin >> n >> q;
    int* arr = new int[n];
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    int* tree = new int[4*n];
    cout << "Tree : ";
    buildTree(arr, 0, n-1, tree, 0);

    while(q--){
        char op;
        int first,second;
        cin >> op >> first >> second;

        if(op == 'q'){
            cout << query(arr,  0, n-1, tree, 0, first-1, second-1) << endl;
        }
        else{
            update(arr, 0, n-1, tree, 0, first-1, second);
        }
    }

    delete [] arr;
    delete [] tree;
}
