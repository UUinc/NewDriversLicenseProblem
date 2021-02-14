#include <stdio.h>
#include <string.h>

int main() 
{
    int agents, order = 1, minutes = 20, i, j, len, index[4];
    char myName[50], names[100], name1[50]="", name2[50]="", name3[50]="", name4[50]=""; 
    
    scanf("%s",myName);
    scanf("%d ",&agents);
    gets(names);
    
    tolower(myName);
    tolower(names);
    
    len = strlen(names);len = strlen(names);
    
    index[0] = 0;
    
    for(i = 0, j = 1; i <= len; i++)
    {
        if(names[i] == ' ')
        {
             index[j] = i+1;
             j++;   
        }         
    }
    
    for(i = 0; i < len;)
    {
        for(j = 0; j < index[1]-1; j++, i++)
            name1[j] = names[i]; name1[j+1] = '\0';
            
        i++;
            
        for(j = 0; j < index[2]-1-index[1]; j++, i++)
            name2[j] = names[i]; name2[j+1] = '\0';
            
        i++;
        
        for(j = 0; j < index[3]-1-index[2]; j++, i++)
            name3[j] = names[i]; name3[j+1] = '\0';
        
        i++;
        
        for(j = 0; j < len-index[3]; j++, i++)
            name4[j] = names[i]; name4[j+1] = '\0';
    }
    
    len = strlen(myName);
    
    for(i = 0; i < len;)
    {
        if(myName[i] > name1[i])
        {
        	order++;	
        	break;
		}   
        else if(myName[i] == name1[i])
            i++;
        else
        	break;
    }
    for(i = 0; i < len;)
    {
        if(myName[i] > name2[i])
        {
        	order++;	
        	break;
		}   
        else if(myName[i] == name2[i])
            i++;
        else
        	break;
    }
    for(i = 0; i < len;)
    {
        if(myName[i] > name3[i])
        {
        	order++;	
        	break;
		}   
        else if(myName[i] == name3[i])
            i++;
        else
        	break;
    }
    for(i = 0; i < len;)
    {
        if(myName[i] > name4[i])
        {
        	order++;	
        	break;
		}   
        else if(myName[i] == name4[i])
            i++;
        else
        	break;
    } 

	switch(agents)
	{
		case 1:
			minutes *= order;	
			break;
		case 2:
			if(order > 2 && order <= 4)
				minutes *= 2;
			else if(order > 4)
				minutes += 40; 
			break;
		case 3:
			if(order > 3)
				minutes *= 2;
			break;
		case 4:
			if(order > 4)
				minutes *= 2;
			break;
	}
	
	printf("%d",minutes);
	
    return 0;
}
