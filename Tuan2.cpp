#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void MaTranKe(char *v,char *r)//n là ??nh
{
	FILE* f;
	f=fopen(v,"rt");
	if(f==NULL)
		return;
	int n;
	fscanf(f,"%d",&n);
	if(n==0)//khong co do thi
		return;
	if(n==1)
	{
		f=fopen(r,"wt");
		fprintf(f,"0\n0\n4");
		return;
	}
	int i=0,j=0;

	int** mt;
    mt = new int*[n];
    for(int i = 0; i < n; i++)
        mt[i] = new int[n];
	//int mt[100][100];

	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			fscanf(f,"%d",&mt[i][j]);
	fclose(f);
	
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		a[i]=0;
	}

	int m=0;
	f=fopen(r,"wt");
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			m=m+mt[i][j];
			a[i]=a[i]+mt[i][j];
			a[j]=a[j]+mt[i][j];
		}	
	}
	fprintf(f,"%d",m);
	fprintf(f,"\n");
	int loai=0,d=0;
	for(i=0;i<n;i++)
	{
		fprintf(f,"%d ",a[i]);
		if(a[i]==(n-1))
			loai=1;
		else if(a[i]==2)
			d++;
	}
	if(m==(n*(n-1))/2)
		fprintf(f,"\n1");
	else if(n==m&&d==n&&n>2)
		fprintf(f,"\n2");
	else if(loai==1&&m==n-1&&n>3)
		fprintf(f,"\n3");
	else fprintf(f,"\n4");
	fclose(f);
}
void DanhSachKe(char *v, char *r)//n là ??nh, m là c?nh
{
	FILE* f;
	f=fopen(v,"rt");
	if(f==NULL)
		return;
	int n,m;
	fscanf(f,"%d",&n);
	fscanf(f,"%d",&m);
	if(n==0)//khong co do thi
		return;
	if(n==1)
	{
		f=fopen(r,"wt");
		fprintf(f,"0\n0\n4");
		return;
	}
	int i=0,j=0,so;

	int *a = new int[n];
	for(i=0;i<n;i++)
	{
		a[i]=0;
	}
	//int a[100]={0};

	int sl=m*2;
	for(i=0;i<sl;i++)
	{
		fscanf(f,"%d",&so);
		a[so]=a[so]+1;
	}
	fclose(f);

	f=fopen(r,"wt");
	fprintf(f,"%d",m);
	fprintf(f,"\n");
	int loai=0,d=0;
	for(i=0;i<n;i++)
	{
		fprintf(f,"%d ",a[i]);
		if(a[i]==(n-1))
			loai=1;
		else if(a[i]==2)
			d++;
	}
	if(m==(n*(n-1))/2)
		fprintf(f,"\n1");
	else if(n==m&&d==n&&n>2)
		fprintf(f,"\n2");
	else if(loai==1&&m==n-1&&n>3)
		fprintf(f,"\n3");
	else fprintf(f,"\n4");
	fclose(f);
}
void main(int argc,char* argv[])
{
	int loai=atoi(argv[2]);
	char a[50]="D:/";
	char *s=argv[3];
	char b[50]="D:/";
	
	strcat(a,s);
	s=argv[4];
	strcat(b,s);
	if(loai==1)
		MaTranKe(a,b);
	else
		DanhSachKe(a,b);
	//getche();
}