bool lemonadeChange(int* bills, int billsSize){
    int nDrawer[3] = {0};
    int i = 0;

    for(i = 0; i < billsSize; i++)
    {
        if(bills[i] == 5)
        {
            nDrawer[0]++;
        }
        else if(bills[i] == 10)
        {
            if(nDrawer[0] > 0)
            {
                nDrawer[1]++;
                nDrawer[0]--;
            }
            else
            {
                break;
            }
        }
        else if(bills[i] == 20)
        {
            if(nDrawer[1] > 0)
            {
                nDrawer[2]++;
                nDrawer[1]--;
                if(nDrawer[0] > 0)
                {
                    nDrawer[0]--;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if(nDrawer[0] > 3)
                {
                    nDrawer[0] = nDrawer[0] - 3;
                }
                else
                {
                    break;
                }
            }
        }
    }

    if(i >= billsSize)
    {
        return true;
    }   

    return false;
}