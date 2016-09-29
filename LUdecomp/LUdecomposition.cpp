// LUdecomposition.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;
 


int main()
{
	int i, j, k, n, m, p, z, d;
	float sum, detA=1;
	bool check=0;
 cout<<"n="; 
 cin>>n;  
  float ** A=new float *[n]; 
  float ** L=new float *[n];
  float ** U=new float *[n];
  float ** Mult=new float *[n];
  float ** M_obr=new float *[n];
  float ** y=new float *[n];
  float ** x=new float *[n];
  float ** MultObr=new float *[n];
  float ** E=new float *[n];
    for (int i=0; i<n; i++) 
	{
        A[i]=new float [n];
        L[i]=new float [n];
        U[i]=new float [n];
		Mult[i]=new float [n];
		M_obr[i]=new float [n];
		y[i]=new float [n];
		x[i]=new float [n];
		MultObr[i]=new float [n];
		E[i]=new float [n];
	}
     cout<<" Vvedite elementi matrici A: \n";
        for (i=0;i<n;i++)
		{
			for (j=0;j<n;j++)
			{
				cin>>A[i][j];
				L[i][j]=0;
				U[i][j]=0;
				L[i][i]=1;
				y[i][i]=1;
			}
		}
    for (j=0;j<n;j++) 
	{
        U[0][j]=A[0][j];
	}
    for (j=1;j<n;j++) 
	{
		if (U[0][0]!=0)
		{
        L[j][0]=A[j][0]/A[0][0]; 
		}
		else
		{
			cout<<"ERROR pervii element matrici A raven 0; delenie na 0 /n";
			system ("pause");
			exit(1);
		}
	}
        
for (i=1;i<n;i++)
{
		for (j=i;j<n;j++)
		{
			sum=0;
			for (k=0;k<i;k++){sum=sum+L[i][k]*U[k][j];}
			U[i][j]=A[i][j]-sum;
		}
			for (j=i+1;j<n;j++)
			{
				if(U[i][i]!=0)
				{
					sum=0;
				    for (k=0;k<i;k++){sum=sum+L[j][k]*U[k][i];}
				    L[j][i]=(A[j][i]-sum)/U[i][i];
				    L[i][i]=1;
				}
				else
				{
					cout<<"ERROR element glavnoi diagonali matrici U raven 0; delenie na 0 /n";
					system ("pause");
					exit(1);
				}
			}
}
for (i=0; i<n; i++)
{
	 for (j=0; j<n; j++)
	 {
		 Mult[i][j] = 0;
		  for ( m = 0; m <n; m++)
            {
                Mult[i][j] += L[i][m] * U[m][j];
            }
	 }
 }
for (i=0; i<n; i++)
{
	detA=detA*U[i][i];
}
for (j=0; j<n; j++)
{
	for(i=0; i<n; i++)
	{
		sum=0;
		if(i==j)
		{
			y[i][j]=1;
		}
		else if (i<j)
		{
			y[i][j]=0;
		}
		else
		{
			for (p=0;p<i;p++)
			{
				sum=sum-L[i][p]*y[p][j];
				y[i][j]=sum;
			}
		}
	}
}
for(j=n-1; j>=0; j--)
{
	x[n-1][j]=y[n-1][j]/U[n-1][n-1];
}
for(j=0; j<n;j++)
{
	for (i=n-2; i>=0; i--)
	{
		sum=0;
			for (z=n-1; z>i; z--)
			{
				sum=(sum+U[i][z]*x[z][j]);
				x[i][j]=(y[i][j]-sum)/U[i][i];
			}
			
	}

}
for(i=0; i<n; i++)
{
    for(j=0; j<n; j++)
	{
      MultObr[i][j]=0;
      for(d=0; d<n; d++)
	  {
		  MultObr[i][j] += A[i][d] * x[d][j];
	  }
	}
}
for (i=0; i<n; i++)
{
	for (j=0; j<n; j++)
	{
		E[i][j]=0;
		E[i][i]=1;
	}
}
for (i=0;i<n;i++)
{
    for (j=0;j<n;j++)
	{
		if(ceil(MultObr[i][j]-0.5)==E[i][j])
		{
		  check=1;
		}
		else
		{
			check=0;
		}
	}
}
cout<<"matrix A \n";
for (i=0; i<n; i++)
{
	for (j=0; j<n; j++)
	{
		cout<<setw(10)<<A[i][j]<<"    ";
	} 
	cout<<"\n"; 
}

cout<<"L matr \n";
for (i=0;i<n;i++)
{
	for (j=0;j<n;j++)
	{
		cout<<setw(10)<<L[i][j]<<"    ";
    }
	cout<<"\n";
} 
cout<<"U matr \n";
for (i=0;i<n;i++)
{
    for (j=0;j<n;j++)
	{
		cout<<setw(10)<<U[i][j]<<"    ";
	}
	cout<<"\n";
}
cout<<"Multiply LU matr \n";
for (i=0;i<n;i++)
{
    for (j=0;j<n;j++)
	{
		cout<<setw(10)<<Mult[i][j]<<"    ";
    }
	cout<<"\n";
}
cout<<"Opredelitel Matrici: = ";
cout<<detA;
cout<<"\n";
cout<<"y \n";
for (i=0;i<n;i++)
{
	for (j=0;j<n;j++)
	{
		cout<<setw(10)<<y[i][j]<<"    ";
    }cout<<"\n";
}

cout<<"Obratnaya matrica x \n";
for (i=0;i<n;i++)
{
    for (j=0;j<n;j++)
	{
		cout<<setw(10)<<x[i][j]<<"    ";
    }
	cout<<"\n";
} 
cout<<"A*Х proizvedenie matric \n";
for (i=0;i<n;i++)
{
    for (j=0;j<n;j++)
	{
		cout<<setw(10)<<ceil(MultObr[i][j]-0.5)<<"    ";
    }
	cout<<"\n";
} 
if(check==1)
{
	cout<<"matrica X naidena verno (X obratnaya ishodnoi A) \n";
}
else
{
	cout<<" ERROR matrica X naidena  ne verno \n";
}

system("pause");
return 0;
}
