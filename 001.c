#include<stdio.h>
#include<string.h>
main()
{
    int i,j,z,k=0,s=0,b[30],a[30];
    char c[90];
    gets(c);
    i=strlen(c);
    for(j=0;j<i;){
        if(c[j]=='|'){
            j++;
        }
        else if(c[j]=='X'){
            b[k]=10;
            j++;
            k++;
        }
        else if(c[j]=='/'){
            b[k]=10-(c[j-1]-48);
            j++;
            k++;
        }
        else if(c[j]=='-'){
            b[k]=0;
            j++;
            k++;
        }
        else{
            b[k]=c[j]-48;
            j++;
            k++;
        }
    }
    for(;i<30;i++){
        a[i]=100;
    }
    i=0;
    j=0;
    for(;j<8;j++){
        if(b[i]==10){
            a[j]=10+b[i+1]+b[i+2];
            i++;
        }
        else{
            if(b[i]+b[i+1]==10){
                a[j]=10+b[i+2];
            }
            else{
                a[j]=b[i]+b[i+1];
            }
            i+=2;
        }
        if(a[j]==100){
            break;
        }
    }
    for(z=0;z<8;z++){
        s+=a[z];
    }
    if(b[i]==10&&b[i+1]==10){
        s+=10+10+10+b[i+2]+b[i+2]+b[i+3];
    }
    else if(b[i]==10&&b[i+1]!=10&&b[i+1]+b[i+2]==10){
        s+=10+b[i+2]+b[i+2]+b[i+3]+10;
    }
    else if(b[i]==10&&b[i+1]!=10&&b[i+1]+b[i+2]!=10){
        s+=10+b[i+1]+b[i+1]+b[i+2];
    }
    else if(b[i]!=10&&b[i]+b[i+1]==10&&b[i+2]==10){
        s+=10+10+10+b[i+3]+b[i+4];
    }
    else if(b[i]!=10&&b[i]+b[i+1]==10&&b[i+2]!=10&&b[i+2]+b[i+3]==10){
        s+=10+10+b[i+2]+b[i+4];
    }
    else if(b[i]!=10&&b[i]+b[i+1]==10&&b[i+2]!=10&&b[i+2]+b[i+3]!=10){
        s+=10+b[i+2]+b[i+2]+b[i+3];
    }
    else if(b[i]!=10&&b[i]+b[i+1]!=10&&b[i+2]==10){
        s+=10+b[i]+b[i+1]+b[i+3]+b[i+4];
    }
    else if(b[i]!=10&&b[i]+b[i+1]!=10&&b[i+2]!=10&&b[i+2]+b[i+3]==10){
        s+=10+b[i]+b[i+1]+b[i+4];
    }
    else if(b[i]!=10&&b[i]+b[i+1]!=10&&b[i+2]!=10&&b[i+2]+b[i+3]!=10){
        s+=b[i]+b[i+1]+b[i+2]+b[i+3];
    }
    printf("%d",s);
}

