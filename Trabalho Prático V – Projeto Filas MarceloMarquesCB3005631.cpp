//Marcelo Marques Araujo CB3005631 Trabalho Prático V – Projeto Filas
#include <iostream>
using namespace std;
#define SIZE 5
int A[SIZE];
int front = -1;
int rear = -1;


bool isempty()
{
 if(front == -1 && rear == -1)
 return true;
 else
 return false;
}


void enqueue ( int value )
{

 if ((rear + 1)%SIZE == front)
    cout<<"Queue is full \n";
 else
 {
  
  if( front == -1)
     front = 0;
 
 rear = (rear+1)%SIZE;
   A[rear] = value;
 }
}


void dequeue ( )
{
 if( isempty() )
  cout<<"Fila esta vazia\n";
 else
 
 if( front == rear )
  front = rear = -1;
 else
  front = (front + 1)%SIZE;
}


void showfront( )
{
 if( isempty())
 cout<<"Fila esta vazia\n";
 else
 cout<<"O proximo da fila senha:"<<A[front];
}


void displayQueue()
{
 if(isempty())
  cout<<"Fila esta vazia\n";
 else
 {
  int i;
  if( front <= rear )
  {
   for( i=front ; i<= rear ; i++)
   cout<<A[i]<<" ";
  }
  else
  {
   i=front;
   while( i < SIZE)
   {
   cout<<A[i]<<" ";
   i++;
   }
   i=0;
   while( i <= rear)
   {
   cout<<A[i]<<" ";
   i++;
   }
  }
 }
}


int main()
{
 int choice, flag=1, value;
 while( flag == 1)
 {
  cout<<"\n1.GERAR SENHA 2.REALIZAR ATENDIMENTO 3.PROXIMA SENHA DA FILA 4.SENHAS AGUARDANDO ATENDIMENTO 5.SAIR\n";
  cin>>choice;
  switch (choice)
  {
  case 1: cout<<"Cadastrar Numero da Senha:\n";
          cin>>value;
          enqueue(value);
          break;
  case 2: dequeue();
          break;
  case 3: showfront();
          break;
  case 4: displayQueue();
          break;
  case 5: flag = 0;
          break;
  }
 }

 return 0;
}