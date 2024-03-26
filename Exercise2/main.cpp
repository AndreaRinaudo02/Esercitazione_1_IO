#include <fstream>
#include <iostream>

int main()
{
    using namespace std;

    double x;                                // x memorizza i valori contenuti nel file
    double y = 0;                            // y memorizza la somma dei primi N valori contenuti nel file
    double N = 0;                            // N memorizza il numero di valori letti

    string file_input = "data.csv";
    ifstream ifs(file_input);                // apre il file di input

    string file_output = "result.csv";
    ofstream ofs(file_output);               // apre il file di output

    if (ifs.is_open())
    {

        if(ofs.is_open())
        {
            while(ifs >> x)
            {
                if (ifs.fail())              // controlla possibili errori nell'estrazione di valori dal file di input
                {
                    cerr <<"Errore: impossibile estrarre un valore corretto da data.csv";
                }

                N = N+1;                     // aggiorna il numero di valori letti
                x = (3./4.)*x - 7./4.;       // si usa una mappa lineare per mappare i valori nell'intervallo [-1;2]
                y = y + x;
                double mean = y/N;
                ofs << mean << "\n";         // stampa il valore della media in una nuova riga del file di output
            }
        }

        else
        {
            cerr << "Errore: impossibile aprire il file di output" << endl;
        }
    }

    else
    {
        cerr << "Errore: impossibile aprire file di imput" << endl;
    }

    ifs.close();                             // i file vengono chiusi (per sicurezza)
    ofs.close();

    return 0;
}
