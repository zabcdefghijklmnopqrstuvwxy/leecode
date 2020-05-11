int maxDistToClosest(int* seats, int seatsSize){
    int max=0,countzero=0,i,posi=-1;
    for(i=0;i<seatsSize;i++)
    {
        if(seats[i]==1)//有人坐着
        {
            if(posi==-1)//第一次出现有人坐着,即左边极端的情况
                    max=i;
            else if(countzero>0)//并非第一次出现有人坐着
            {   
                    countzero++;
                if(countzero/2>max)//出现符合要求的
                {
                    max=countzero/2;
                }
            }
            countzero=0;
            posi=i;
        }
        else if(seats[i]==0)//座位是空着的
            countzero++;
    }
    if(countzero>max)//处理右边的极端情况
        max=countzero;
    return max;
}