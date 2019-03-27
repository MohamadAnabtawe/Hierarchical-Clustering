# -*- coding: utf-8 -*-
"""
Created on Sun Jan 13 08:43:27 2019

@author: Mohamad Anabtawe
"""

import numpy as np
from scipy.cluster.hierarchy import linkage, dendrogram
from scipy.spatial.distance import pdist,squareform
n=5;
"""x=np.random.rand(n,2)"""

x=np.array([[1,1],[1,1.1],[3,3],[3.5,4],[8,9]]);

distance_matrix=np.matrix(squareform(pdist(x,metric='euclidean')));
dist=np.copy(distance_matrix)


""" initialize the linkage matrix """
linkage_matrix=np.zeros([n-1,4])

""" index for building the linkage matrix """
linkage_index=0  

""" for each row in linkage matrix we calculate the size of the combined cluster """
cluster_size=[1]*n 

""" for each object we update the cluster that this object related to """
cluster=[i for i in range(0,n)]
new_cluster_index=n

""" 
helper method that return :
    the min distance between 2 clusters/objects 
    and the position (row and column) 
"""
max_vlaue=np.max(dist)

def min_distance():
    min_dist=max_vlaue
    i=1
    j=0
    for k in range(0,n):
        for l in range(0,n):
           if dist[k,l]<min_dist and dist[k,l]>0:
               min_dist=dist[k,l]
               i=k
               j=l
    return i,j,min_dist

""" 
    create the linkage matrix 
"""
while linkage_index < n-1: 
    row,col,min_dist=min_distance()
    linkage_matrix[linkage_index,0]=cluster[row]
    linkage_matrix[linkage_index,1]=cluster[col]
    linkage_matrix[linkage_index,2]=min_dist
    cluster_size.append(cluster_size[cluster[row]]+cluster_size[cluster[col]])
    linkage_matrix[linkage_index,3]=cluster_size[new_cluster_index]
    linkage_index=linkage_index+1

    for i in range(0,n):
        if cluster[i]==cluster[row] and i!=row:
                cluster[i]=new_cluster_index

        if cluster[i]==cluster[col] and i!=col:
                cluster[i]=new_cluster_index
    cluster[row]=new_cluster_index
    cluster[col]=new_cluster_index                 
    for i in range(0,n):
        for j in range(0,n):
              if cluster[i]==cluster[j] :
                  dist[i,j]=0
                  dist[j,i]=0                
    new_cluster_index=new_cluster_index+1

   
dendrogram(linkage_matrix) 

