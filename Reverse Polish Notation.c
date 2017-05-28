#include<stdio.h>
#include<string.h>
main()
{
    int i;
	char init[100];
	float s = 0,onit[3];
	gets(init);
	onit[0]=init[0];
	onit[1]=init[1];
	for(i = 2;i < strlen(init);i += 2)
	{
		if(init[i] == '+'||init[i] == '-'||init[i] == '*'||init[i] == '/')
		{
			switch(init[i])
			{
				case '+' :
					s = onit[0] + onit[1]-96;
					onit[0] = s+48;
					onit[1] = init[i+1];
					break;
				case '-' :
					s = onit[0] - onit[1];
					onit[0] = s+48;
					onit[1] = init[i+1];
					break;
				case '*' :
					s = (onit[0]-48) * (onit[1]-48);
                    onit[0] = s+48;
					onit[1] = init[i+1];
					break;
				case '/' :
					if(init[i-1] == '0')
						printf("error！！！！");
					else
						s = (onit[0]-48) / (onit[1]-48);
						onit[0] = s+48;
						onit[1] = init[i+1];
					break;
			}
		}
	}
	printf("%f\n",s);
}
