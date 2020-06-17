#include <iostream>
#include <string>
#include <array>

using namespace std;

class Tablero
{
private:
    std::array<char, 9> Espacio = {'1','2','3','4','5','6','7','8','9'};
public:
    Tablero(/* args */);
    ~Tablero();
    bool Pintar(char,int);
    char ComprobarSequencia();
    void Refrescar();
    int Longitud();
    char Valor(int);
};

Tablero::Tablero(/* args */)
{
    
}

Tablero::~Tablero()
{
}
bool Tablero::Pintar (char id, int i)
{
    if ((Espacio[i-1] - '0') == i)
    {
        Espacio[i-1] = id;
        return true;
    }
    return false;
}

char Tablero::ComprobarSequencia() {
   for(int i=0; i < 3; i++)
    {
        int j = i * 3;
        if(Espacio[j] == Espacio[j+1] && Espacio[j] == Espacio[j+2])
        {
            return Espacio[j];
        }
        else if (Espacio[i] == Espacio[i+3] && Espacio[i] == Espacio[i+6])
        {
            return Espacio[i];
        }
    }
    if(Espacio[0] == Espacio[4] && Espacio[4] == Espacio[8])
    {
        return Espacio[0];
    }
     if(Espacio[2] == Espacio[4] && Espacio[4] == Espacio[6])
    {
        return Espacio[2];
    }
return ' ';

}

void Tablero::Refrescar()
{
    cout << Espacio[0] << " | " << Espacio[1] << " | " << Espacio[2] << "\n";
    cout << "____________" << "\n";
    cout << Espacio[3] << " | " << Espacio[4] << " | " << Espacio[5] << "\n";
    cout << "____________" << "\n";
    cout << Espacio[6] << " | " << Espacio[7] << " | " << Espacio[8] << "\n";
    
}

int Tablero::Longitud()
{
    return Espacio.size();
}
char Tablero::Valor(int pos)
{
    return Espacio[pos];
}

class Jugador
{
private:
    /* data */
public:
    Jugador();
    Jugador(char id);
    ~Jugador();
    char Identificador;
};

Jugador::Jugador() {}

Jugador::Jugador(char id)
{
    Identificador = id;
}

Jugador::~Jugador()
{
}

class Juego
{
private:
    /* data */
public:
    Juego();
    Juego(string name, Tablero tabl, Jugador jug1, Jugador jug2);
    ~Juego();

    Tablero Tablero1;
    Jugador Jugador1;
    Jugador Jugador2;
    string Name;
    Jugador Ganador();
};

Juego::Juego() {}

Juego::Juego(string name, Tablero tabl, Jugador jug1, Jugador jug2)
{
    Name = name;
    Tablero1 = tabl;
    Jugador1 = jug1;
    Jugador2 = jug2;
}

Juego::~Juego()
{
}

Jugador Juego::Ganador()
{
  return Jugador1;
}

bool PermiteMovimiento(Juego juego) {
    for(int i = 0; i < juego.Tablero1.Longitud(); i++)
    {
        char val = juego.Tablero1.Valor(i);
        if(val != juego.Jugador1.Identificador && val != juego.Jugador2.Identificador) 
        {
            return true;
        }
    }
    return false;
}

main() 
{
   Jugador NJugador1 = Jugador('X');
   Jugador NJugador2 = Jugador('O');
   Tablero NTablero = Tablero();
   Juego NJuego = Juego("TTT", NTablero, NJugador1, NJugador2);
   int pos;
   char turno = NJugador1.Identificador;

    do {
        NJuego.Tablero1.Refrescar();
        if (turno == NJugador1.Identificador)
        {
            cout << "Jugador 1: Entre la posicion:";
            cin >> pos;
            NJuego.Tablero1.Pintar(NJugador1.Identificador, (int)pos); 
            turno = NJugador2.Identificador; 
        }
         else
        {
            cout << "Jugador 2: Entre la posicion:";
            cin >> pos;
            NJuego.Tablero1.Pintar(NJugador2.Identificador, (int) pos);
            turno = NJugador1.Identificador; 

        }

    }  while(PermiteMovimiento(NJuego));
    
       
}