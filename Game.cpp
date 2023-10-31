#include<iostream>
using namespace std;
 
void mostrarinstrucciones() //Una funcion compuesta unicamente por el texto de las instrucciones
{
    cout<<"En Mastermind compiten 2 jugadores, el jugador que introduce el codigo y el jugador que lo intenta acertar. El jugador que hace el codigo coloca en secreto su combinacion compuesta por 4 numeros. El usuario para acertar la combinacion puede usar 4 numeros (del 1 al 4) que se pueden repetir, ademas saltara un aviso si alguno de los numeros introducidos no corresponde al abanico de numeros mencionado anteriormente. La persona que tiene que descifrar el codigo lo colocara a la espera de que el otro jugador le empiece a dar pistas. Para que el juego no sea imposible se le iran dando pistas: si el hueco en el que el usuario ha anadido el numero coincide en numero y posicion se le avisara y por cada numero acertado pero en un lugar equivocado de la secuencia tambien. El usuario tiene diez intentos para acertar el codigo y en el momento que gane saltara un mensaje diciendo ENHORABUENA HAS ACERTADO EL CODIGO! sino le saltara un mensaje diciendo LO SIENTO NO HAS CONSEGUIDO ADIVINAR EL CODIGO, OTRA VEZ SERA!"<<endl;
 
}
void jugada() //Es la funcion principal, en la que se desarrolla la mayoria del codigo del juego
{
system("cls"); //Es un "borrador" de pantalla
int i;
int datos[4]; //Array para contener los datos introducidos por el usuario
for (i=0; i<10; i++)// For que equivale al numero de intentos que tiene el usuario para acertar el enigma
{
 
cout<<"Estas en el intento "<<(i+1)<<" por favor introduce cuatro numero del 1 al 4"<<endl;
cout<<"Primer digito del codigo"<<endl;
cin>>datos[0];
cout<<"Segundo digito del codigo"<<endl;
cin>>datos[1];
cout<<"Trecer digito del codigo"<<endl;
cin>>datos[2];
cout<<"Cuarto digito del codigo"<<endl;
cin>>datos[3];   
 
if (datos[0]<1||datos[0]>4)// Avisos que se le hace al usuario para que no introduzca numeros que no pertenezcan al rango estipulado
{
    cout<<"Has anadido un numero que no debes anadir, ten cuidado"<<endl;
cout<<endl<<endl;
}
if (datos[1]<1||datos[1]>4)
{
cout<<"Has anadido un numero que no debes anadir, ten cuidado"<<endl;
cout<<endl<<endl;
}
if (datos[2]<1||datos[2]>4)
{
cout<<"Has anadido un numero que no debes anadir, ten cuidado"<<endl;
cout<<endl<<endl;
}
if (datos[3]<1||datos[3]>4)
{
cout<<"Has anadido un numero que no debes anadir, ten cuidado"<<endl;
cout<<endl<<endl;
}
 
cout<< "Tu numero es el ----------->"<<datos[0]<<datos[1]<<datos[2]<<datos[3]<<"<-----------"<<endl;
 
int correcto=0;
int aproximacion=0;
 
if (datos[0]==1)    //Condicion en la que si el primer dato introducido coincide en numero y en posicion con el primer digito del numero a adivinar suma en el contador de la variable "CORRECTO", lo mismo pasa con los demás "if" de debajo
{
    correcto++;
}
 
if (datos[1]==2)    
{
    correcto++;
}
 
if (datos[2]==4)    
{
    correcto++;
}
 
if (datos[3]==4)    
{
    correcto++;
}
 
if(datos[0]==2||datos[0]==4)    //Condicion en la que si el primer dato introducido coincide en numero pero NO en posicion con el primer digito del numero a adivinar sumará en el contador de la variable "APROXIMACION", lo mismo pasa con los demás "if" de debajo
{
    aproximacion++; 
}
 
if(datos[1]==1||datos[1]==4)
{
    aproximacion++; 
}
 
if(datos[2]==2||datos[2]==1)
{
    aproximacion++; 
}
 
if(datos[3]==2||datos[3]==1)
{
    aproximacion++; 
}
 
 
 
cout<<"Has acertado "<<correcto<<" numeros en la posicion correcta"<<endl; //Pista que se le la al usuario de cuantos datos introducidos coinciden con el primer digito del enigma y estan en posicion correcta
cout<<"    "<<endl;
cout<<"Has acertado "<<aproximacion<<" numeros pero no en la posicion correcta"<<endl; //Pista que se le da al usuario de cuantos datos introducidos coinciden con algun digito del enigma (por lo tanto no está en la posicion correcta)
 
if(datos[0]==1&&datos[1]==2&&datos[2]==4&&datos[3]==4) //Condicion en la que si todos los numeros coindicen en posicion con el enigma salga un mensaje de que lo ha adivinado
{
system("cls");
 cout<<  "ENHORABUENA HAS ACERTADO EL CODIGO!"<<endl;
 
 exit(0);//Para que salga de la pantalla del juego
}
cout<<endl<<endl;
}
system("cls");
cout<<"LO SIENTO NO HAS CONSEGUIDO ADIVINAR EL CODIGO, OTRA VEZ SERA!"; //Si el usuario no ha acertado el codigo en los diez intentos que comprendian el "for" le saldra un aviso de que ha perdido el juego
exit(0);
}
 
void menuinicial() //La funcion del menu en la que si el usuario introduce un 1 se abra la funcion de jugada y si introduce el 2 se abra la funcion de las instrucciones
{
system("cls");
int opcion;
do
{
cout<<"1.- Juego"<<endl;
cout<<"2.- Intrucciones"<<endl;
 
    cin>> opcion;
 
    if(opcion==1)
    {
        jugada();
    }
 
    if(opcion==2)
    {
     mostrarinstrucciones();
    }
 
        }
    while(opcion!=1||opcion!=2);
}
 
int main() //Funcion principal en la que unicamente esta el menu
{
menuinicial();
 
    return 0;
}