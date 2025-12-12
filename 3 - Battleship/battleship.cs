using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;

public class BatallaNaval
{
    const int TamanioTablero = 10;
    
    char[,] tableroJugador = new char[TamanioTablero, TamanioTablero];
    char[,] tableroPC = new char[TamanioTablero, TamanioTablero];
    char[,] tableroVisiblePC = new char[TamanioTablero, TamanioTablero];

    readonly int[] TamanosBarcos = { 5, 4, 3, 3, 2 };

    Random random = new Random();

    int barcosJugadorRestantes = 0;
    int barcosPCRestantes = 0;

    public static void Main(string[] args)
    {
        var juego = new BatallaNaval();
        juego.EmpezarJuego();
    }

    void EmpezarJuego()
    {
        for (int i = 0; i < TamanioTablero; i++)
        {
            for (int j = 0; j < TamanioTablero; j++)
            {
                tableroJugador[i, j] = '~';
                tableroPC[i, j] = '~';
                tableroVisiblePC[i, j] = '~';
            }
        }

        Console.Title = "batalla naval";
        Console.WriteLine("\n--- batalla naval ---");
        Console.WriteLine("los barcos a colocar son de tamaños 5, 4, 3, 3, y 2.");
        Console.WriteLine($"casillas de barco totales: {TamanosBarcos.Sum()}.");
        Console.Write("presiona enter para iniciar la colocación de barcos... ");
        Console.ReadLine();

        barcosJugadorRestantes = TamanosBarcos.Sum();
        barcosPCRestantes = TamanosBarcos.Sum();

        ColocarBarcosJugador(tableroJugador);
        ColocarBarcosPC(tableroPC);

        while (barcosJugadorRestantes > 0 && barcosPCRestantes > 0)
        {
            TurnoJugador(tableroPC, tableroVisiblePC, ref barcosPCRestantes);
            if (barcosPCRestantes <= 0) break;

            TurnoPC(tableroJugador, ref barcosJugadorRestantes);
            if (barcosJugadorRestantes <= 0) break;
        }

        Console.Clear();
        Console.WriteLine("=======================================");
        if (barcosPCRestantes <= 0)
        {
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine("el jugador ha ganado. la flota de la pc ha sido hundida.");
        }
        else
        {
            Console.ForegroundColor = ConsoleColor.Red;
            Console.WriteLine("la pc ha ganado. la flota del jugador ha sido hundida.");
        }
        Console.ForegroundColor = ConsoleColor.Gray;
        Console.WriteLine("=======================================");

        Console.WriteLine("\ntablero final del jugador:");
        Eltablero(tableroJugador, true);

        Console.WriteLine("\ntablero de la pc:");
        Eltablero(tableroPC, true);

        Console.Write("\npresiona enter para salir...");
        Console.ReadLine();
    }

    void Eltablero(char[,] t, bool mostrarBarcos)
    {
        Console.Write("  ");
        for (int j = 0; j < TamanioTablero; j++)
        {
            Console.Write(j + " ");
        }
        Console.WriteLine();

        for (int i = 0; i < TamanioTablero; i++)
        {
            Console.Write(i + " ");
            for (int j = 0; j < TamanioTablero; j++)
            {
                char celda = t[i, j];

                if (!mostrarBarcos && celda == 'B')
                {
                    celda = '~';
                }

                ConsoleColor colorCelda = ConsoleColor.Gray;
                string caracter = celda.ToString();

                if (celda == '~')
                {
                    colorCelda = ConsoleColor.Blue;
                }
                else if (celda == 'B')
                {
                    colorCelda = ConsoleColor.Yellow;
                }
                else if (celda == 'X')
                {
                    colorCelda = ConsoleColor.Red;
                }
                else if (celda == 'O')
                {
                    colorCelda = ConsoleColor.DarkGray;
                }

                Console.ForegroundColor = colorCelda;
                Console.Write(caracter + " ");
                Console.ForegroundColor = ConsoleColor.Gray;
            }
            Console.WriteLine();
        }
    }

    bool ValidarPosicion(char[,] t, int x, int y, int n, int direc)
    {
        if (direc == 1)
        {
            if (x + n > TamanioTablero) return false;
        }
        else
        {
            if (y + n > TamanioTablero) return false;
        }

        for (int k = 0; k < n; k++)
        {
            if (direc == 1)
            {
                if (t[y, x + k] == 'B') return false;
            }
            else
            {
                if (t[y + k, x] == 'B') return false;
            }
        }
        return true;
    }

    void Colocar(char[,] t, int x, int y, int n, int direc)
    {
        for (int k = 0; k < n; k++)
        {
            if (direc == 1)
            {
                t[y, x + k] = 'B';
            }
            else
            {
                t[y + k, x] = 'B';
            }
        }
    }

    void ColocarBarcosJugador(char[,] t)
    {
        int direc, x, y;

        foreach (int n in TamanosBarcos)
        {
            bool colocado = false;
            while (!colocado)
            {
                Console.Clear();
                Console.WriteLine("--- colocación de barcos ---");
                Eltablero(t, true);

                Console.WriteLine($"\nseleccione la posición para el barco de tamaño {n}.");
                Console.Write("orientación - horizontal (1) o vertical (2): ");
                
                if (!int.TryParse(Console.ReadLine(), out direc) || direc < 1 || direc > 2)
                {
                    Console.WriteLine("opción de orientación no válida. intente de nuevo.");
                    Thread.Sleep(1500);
                    continue;
                }

                Console.Clear();
                Console.WriteLine("--- colocación de barcos ---");
                Eltablero(t, true);

                Console.WriteLine($"\nintroduzca la coordenada inicial (esquina superior/izquierda) para el barco de {n} casillas.");

                Console.Write("coordenada x (columna 0-9): ");
                if (!int.TryParse(Console.ReadLine(), out x) || x < 0 || x >= TamanioTablero)
                {
                    Console.WriteLine("coordenada x fuera de rango (0-9).");
                    Thread.Sleep(1500);
                    continue;
                }

                Console.Write("coordenada y (fila 0-9): ");
                if (!int.TryParse(Console.ReadLine(), out y) || y < 0 || y >= TamanioTablero)
                {
                    Console.WriteLine("coordenada y fuera de rango (0-9).");
                    Thread.Sleep(1500);
                    continue;
                }

                if (ValidarPosicion(t, x, y, n, direc))
                {
                    Colocar(t, x, y, n, direc);
                    colocado = true;
                }
                else
                {
                    Console.WriteLine("error: la posición no es válida (choca o se sale del tablero).");
                    Thread.Sleep(2000);
                }
            }
        }
    }

    void ColocarBarcosPC(char[,] t)
    {
        foreach (int n in TamanosBarcos)
        {
            bool colocado = false;
            while (!colocado)
            {
                int x = random.Next(0, TamanioTablero);
                int y = random.Next(0, TamanioTablero);
                int direc = random.Next(1, 3);

                if (ValidarPosicion(t, x, y, n, direc))
                {
                    Colocar(t, x, y, n, direc);
                    colocado = true;
                }
            }
        }
    }

    void TurnoJugador(char[,] tPC, char[,] tVisiblePC, ref int barcosPC)
    {
        int x, y;
        bool disparoValido = false;

        while (!disparoValido)
        {
            Console.Clear();
            Console.WriteLine("--- tu tablero ---");
            Eltablero(tableroJugador, true);
            Console.WriteLine("\n--- tablero de la pc ---");
            Eltablero(tVisiblePC, false);

            Console.WriteLine("\nturno del jugador.");
            Console.Write("coordenada x para disparar (0-9): ");
            if (!int.TryParse(Console.ReadLine(), out x) || x < 0 || x >= TamanioTablero)
            {
                Console.WriteLine("coordenada x no válida. presione enter para reintentar.");
                Console.ReadLine();
                continue;
            }

            Console.Write("coordenada y para disparar (0-9): ");
            if (!int.TryParse(Console.ReadLine(), out y) || y < 0 || y >= TamanioTablero)
            {
                Console.WriteLine("coordenada y no válida. presione enter para reintentar.");
                Console.ReadLine();
                continue;
            }

            if (tVisiblePC[y, x] != '~')
            {
                Console.WriteLine($"ya se disparó a esta casilla ({tVisiblePC[y, x]}). presione enter para reintentar.");
                Console.ReadLine();
                continue;
            }

            disparoValido = true;

            if (tPC[y, x] == 'B')
            {
                tPC[y, x] = 'X';
                tVisiblePC[y, x] = 'X';
                barcosPC--;
                Console.WriteLine("\n¡impacto! has golpeado un barco de la pc.");
            }
            else
            {
                tPC[y, x] = 'O';
                tVisiblePC[y, x] = 'O';
                Console.WriteLine("\nagua. el disparo falló.");
            }
        }

        Console.WriteLine($"casillas restantes de la pc: {barcosPC}. presiona enter para continuar.");
        Console.ReadLine();
    }

    void TurnoPC(char[,] tJugador, ref int barcosJugador)
    {
        int x, y;

        Console.WriteLine("\n--- turno de la pc ---");
        
        do
        {
            x = random.Next(0, TamanioTablero);
            y = random.Next(0, TamanioTablero);
        } while (tJugador[y, x] == 'X' || tJugador[y, x] == 'O');

        Console.WriteLine($"la pc dispara a la coordenada ({x}, {y}).");
        Thread.Sleep(1500);

        if (tJugador[y, x] == 'B')
        {
            tJugador[y, x] = 'X';
            barcosJugador--;
            Console.WriteLine("¡impacto! la pc ha golpeado un barco del jugador.");
        }
        else
        {
            tJugador[y, x] = 'O';
            Console.WriteLine("agua. la pc falló el disparo.");
        }

        Console.WriteLine($"casillas restantes del jugador: {barcosJugador}. presiona enter para tu turno.");
        Console.ReadLine();
    }
}