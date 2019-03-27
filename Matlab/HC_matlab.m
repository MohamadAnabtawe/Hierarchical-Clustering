clc;
clear All;
%x=rand(20,2)+10;
x=[1,1;1,1.1;3,3;3.5,4;8,9];
n=length(x);
y=pdist(x);
distace_matrix=squareform(y);
dist=distace_matrix;
linkage_matrix=zeros(n-1,3);
k=1;  

for i=1:n
    dist(i,i)=inf;
end
[i,j,min_dist] = min_distance(dist);

while min_dist<inf
    new_row=min(dist(i,:),dist(j,:));
    new_row(i)=inf;
    new_row(j)=inf;
    dist(i,:)=inf;
    dist(j,:)=inf;
    dist(:,i)=inf;
    dist(:,j)=inf;
    new_col=[new_row' ; inf];
    n=n+1;
    dist(n,:)=new_row;
    dist(:,n)=new_col;
    linkage_matrix(k,:)=[j i min_dist];
    k=k+1;
    [i,j,min_dist] = min_distance(dist);
end

figure
dendrogram(linkage_matrix);



