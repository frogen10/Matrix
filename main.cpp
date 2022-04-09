#include <iostream>
#include <random>
#include <cstdlib>
#include <math.h>
using namespace std;

void wypisz(int **, int, int);
void wypisz(double **, int);
int ** tworz( int, int);
int slad(int **, int, int);
int **transp(int **, int, int);
int *kol(int **, int, int,int);
void wypisz(int *, int);
int **suma(int**,int**,int,int);
int **iloraz(int**,int**,int,int,int);
int det(int**,int);
int **wpisz(int,int);
double **revers(int **,int);
int main(){
	int m,n,n2,m2;
	int **tab,**tab2, **tt;
	char which,a;
	while(true)
	{
		cout<<"a. Utwórz randomową macierz,\nb. Wpisz swoją macierz,\nc. Zamień macierze,\n___________________\n1. Macierz transponowana,\n2. Kolumna macierzy,\n3. Ślad macierzy,\n4. Dodawanie macierzy,\n5. Mnożenie macierzy,\n6. Wyznacznik macierzy,\n7. Macierz odwrotna.";
		cout<<"\nWybierz a-c lub 1-7: ";
		cin>>a;
		system("clear");
		switch (a)
		{
      case 'a': //random matrix
        cout<<"Do której macierzy A czy B: ";
        cin>>which;
        cout<<"Podaj rozmiar macierzy: ";
        if(which=='a' || which=='A')
        {
          cin>>n>>m;
          tab = tworz(n, m);
          wypisz(tab, n, m);
        }
        else if(which=='B'|| which=='b')
        {
          cin>>n2>>m2;
          tab2 = tworz(n2,m2);
          wypisz(tab2, n2, m2);
        }
        else
          cout<<"Błąd w wczytania znaku";
        break;
      case 'b':
        cout<<"Podaj do której macierzy A czy B oraz rozmiar: ";
        cin>>which>>n>>m;
        cout<<"Proszę wpisać macierz:\n";
        if(which=='a'||which=='A')
          tab = wpisz(n,m);
        else if(which=='b'||which=='B')
          tab2 = wpisz(n2,m2);
        else
          cout<<"coś poszło nie tak!";

        break;
      case 'c': //zamiana A z B
        tt=tab;
        tab=tab2;
        tab2=tt;
        wypisz(tab, n, m);
        wypisz(tab2, n2, m2);
        break;

      case '1': //transponowana
        cout<<"Którą macierz chcesz transponować A czy B:";
        cin>>which;
        if(which=='a' || which=='A')
        {
          tab = transp(tab, m, n);
          int tmp;
          tmp=m;
          m=n;
          n=tmp;
          wypisz(tab, n, m);
        }
        else if(which=='B'|| which=='b')
        {
          tab2 = transp(tab2, m2, n2);
          int tmp;
          tmp=m2;
          m2=n2;
          n2=tmp;
          wypisz(tab2, n2, m2);
        }
        else
          cout<<"Błąd w wczytania znaku";
        break;
      case '2': //wypisz kolumnę
        wypisz(tab,n,m);
        int k;
        cout<<"Podaj macierz oraz kolumnę, którą chcesz wypisać: ";
        cin>>which>>k;
        if(which=='a' || which=='A')
        {
          wypisz(tab, n, m);
          wypisz(kol(tab, n,m,k),m);
          
        }
        else if(which=='B'|| which=='b')
        {
          wypisz(tab2, n2, m2);
          wypisz(kol(tab2, n2,m2,k),m2);
        }
        else
          cout<<"Błąd w wczytania znaku";
        cout<<endl;
        break;
      case '3': //ślad matrixa
        cout<<"Ślad której macierzy chcesz wyznaczyć A czy B: ";
        cin>>which;
        if(which=='a' || which=='A')
        {
          wypisz(tab, n, m);
          cout << slad(tab, n, m);
          
        }
        else if(which=='B'|| which=='b')
        {
          wypisz(tab, n2, m2);
          wypisz(kol(tab, n2,m2,k),m2);
        }
        else
          cout<<"Błąd w wczytania znaku";
        cout<<endl;
        
        break;
      case '4': //suma macierzy
        wypisz(tab, n, m);
        cout<<endl;
        wypisz(tab2, n2, m2);
        cout<<endl;
        wypisz(suma(tab,tab2, n, m),n,m);
        cout<<endl;
        break;
      case '5': //mnożenie macierzy
        wypisz(tab, n, m);
        cout<<endl;
        wypisz(tab2, n2, m2);
        cout<<endl;
        if (m == n2)
        {
          tt = iloraz(tab,tab2, n, m, m2);
          wypisz(tt,n,m2);
          cout<<"Do której macierzy zapisać A czy B: ";
          cin>>which;
          if(which=='A'||which=='a')
            tab = tt;
          else if(which=='B'||which=='b')
            tab2 = tt;
        }
        else
          cout<<"Nie można pomnożyć macierzy";
        cout<<endl;
        break;
      case '6': //wyznacznik,
        cout<<"Wyznacznik której macierzy chcesz wyznaczyć A czy B: ";
        cin>>which;
        if(which=='a' || which=='A')
        {
          wypisz(tab, n, m);
          if (n!=m)
            cout<<"nie można wyznaczyć wyznacznika";
          else
            cout << det(tab, n)<<endl;
          
        }
        else if(which=='B'|| which=='b')
        {
          wypisz(tab2, n2, m2);
          if (n2!=m2)
            cout<<"nie można wyznaczyć wyznacznika";
          else
            cout << det(tab2, n2)<<endl;
        }
        else
          cout<<"Błąd wczytania znaku";
        cout<<endl;
        break;
      case '7': //odwrotana
        cout<<"Odwrotność której macierzy chcesz wyznaczyć A czy B: ";
        cin>>which;
        if(which=='a' || which=='A')
        {
          wypisz(tab, n, m);
          if (n!=m)
            cout<<"nie można wyznaczyć wyznacznika";
          else
            wypisz(revers(tab, n),n);
        }
        else if(which=='B'|| which=='b')
        {
          wypisz(tab2, n2, m2);
          if (n2!=m2)
            cout<<"nie można wyznaczyć wyznacznika";
          else
            wypisz(revers(tab2, n2),n2);
        }
        else
          cout<<"Błąd wczytania znaku";
        cout<<endl;
        break;
      default:
        return 0;
		}
	}
}

int ** tworz(int n, int m){
	int **t = new int *[n];
	for (int i = 0; i < n; ++i)
		t[i] = new int[m];
	
	random_device R;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			t[i][j] = R() % 21-10;
	return t;
}

int slad(int **t, int n, int m){
	int suma = 0;
	for (int i = 0; i < m && i<n; ++i)
		suma += t[i][i];
	return suma;
}

int **transp(int **t, int n, int m){
	int **t2 = new int *[n];
	for (int i = 0; i < n; ++i)
		t2[i] = new int[m];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			t2[i][j] = t[j][i];
	return t2;
}

int *kol(int **t, int n, int m, int k){
	int *kol = new int [n];
	for (int i = 0; i < m; ++i)
		kol[i] = t[k - 1][i];
	return kol;
}

int **suma(int **t,int **t2,int n,int m){
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			t[i][j] += t2[i][j];
	return t;
}
//ilość wierszy i kolumn w a/ ilość kolumn w b
int **iloraz(int **t,int **t2,int n,int m, int p) {	
	int s;
	int i,j,k;
	int **C = new int *[n];
	for (int i = 0; i < n; ++i)
		C[i] = new int[p];
  for(i = 0; i < n; i++)
  {
    for(j = 0; j < p; j++)
    {
      s = 0;
      for(k = 0; k < m; k++) 
        s += t[ i ][ k ] * t2[ k ][ j ];
      C [ i ][ j ] = s;
    }
  }
	return C;
}

int det(int **t,int n){
	long long int d = 0;
	if (n==1)
		return t[0][0];
	else
	{
		for(int i=0;i<n;++i)
		{
			int **tt = new int *[n-1];
			for (int j = 0; j < n-1; ++j)
			{
				tt[j] = new int[n-1];
			}
			for(int j=0;j<n-1;++j)
			{
				for(int k=0;k<n-1;++k)
				{
					if(k>=i)
						tt[j][k]=t[j+1][k+1];
					else
						tt[j][k]=t[j+1][k];
				}
			}
			d+=pow(-1,i)*t[0][i]*det(tt,n-1);
		}
	}
	return d;
}

double **revers(int **t,int n){
  int d=det(t,n);
  
	double **tt = new double *[n];
	for (int j = 0; j < n; ++j)
		tt[j] = new double[n];
  if (d==0)
  {
    cout<<"wyznacznik macierzy równy 0"<<endl;
    return tt;
  }
	int k=0,l=0;
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{

			int **temp = new int *[n-1];
			for (int h = 0; h < n-1; ++h)
			  temp[h] = new int[n-1];
			for(int m=0;m<n-1;++m)
			{
				for(int o=0;o<n-1;++o)
				{
				  if(m>=i&&o>=j)
						temp[m][o]=t[m+1][o+1];
          else if(m<i&&o>=j)
						temp[m][o]=t[m][o+1];
          else if(m>=i&&o<j)
						temp[m][o]=t[m+1][o];
					else
						temp[m][o]=t[m][o];
        }
			}

			tt[j][i]=pow(-1,i+j)*det(temp,n-1)/d;
      for (int h = 0; h < n-1; ++h)
			  delete [] temp[h];
      delete [] temp;
		}
	}
	return tt;
}

void wypisz(double ** t, int n){
  for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			cout << t[i][j]<<" ";
		cout << endl;
	}
}

int **wpisz(int n,int m){
	int **t = new int *[n];
	for (int i = 0; i < n; ++i)
		t[i] = new int[m];
	
	for(int i = 0; i < n; ++i)
    	for(int j = 0; j < m; ++j) 
			cin >> t[i][j];
	return t;
}

void wypisz(int *t, int m){
	for (int i = 0; i < m; ++i)
		cout<<t[i]<<" ";
}

void wypisz(int **t, int n, int m){
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			cout << t[i][j]<<" ";
		cout << endl;
	}
}