bool canConstruct(char * ransomNote, char * magazine){
    int nHash[256];
    int i = 0;

    if(strlen(magazine) <= 0 && strlen(ransomNote) > 0)
    {
        return false;
    }

    for(i = 0; i < 256; i++)
    {
        nHash[i] = 0;
    }

    for(i = 0; i < strlen(magazine); i++)
    {
        nHash[magazine[i]]++;
    }

    for(i = 0; i < strlen(ransomNote); i++)
    {
        if(nHash[ransomNote[i]] > 0)
        {
            nHash[ransomNote[i]]--;
        }
        else
        {
            return false;
        }
    }

    return true;
}