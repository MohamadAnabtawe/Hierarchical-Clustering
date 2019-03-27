function [i,j,min_dist] = min_distance(dist)
    [temp,temp_pos1]=min(dist);
    [min_dist,temp_pos2]=min(temp);
    i=temp_pos1(temp_pos2);
    j=temp_pos2;
end

