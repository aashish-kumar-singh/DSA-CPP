/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.
*/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool canFinish(int numCourses,vector<vector<int>>& prerequisites){
    vector<vector<int>>adj(numCourses);
    for(auto it: prerequisites){
        adj[it[1]].push_back(it[0]);
    }
    vector<int>indegree(numCourses,0);
    for(int i=0;i<numCourses;i++){
        for(auto it: adj[i]){
            indegree[it]++;
        }
    }
    queue<int>q;
    int count=0;
    for(int i=0;i<numCourses;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node=q.front();
        count++;
        q.pop();
        for(auto it:adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    return count==numCourses;
}
int main(){
return 0;
}