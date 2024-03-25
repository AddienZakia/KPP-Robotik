/**
 * Addien Zakia Hidayat
 * Departemen Matematika
 */

#include <iostream>

using namespace std;

void printArea(char area[], int n, int m)
{
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << area[index];
            index++;
        }
        cout << endl;
    }
}

int findPosition(char area[], char symbol, int length)
{
    int pos = 0;
    for (int i = 0; i < length; i++)
    {
        if (area[i] == symbol)
            pos = i;
    }

    return pos;
}

void robotMove(char area[], char perintah[], int n, int m, int panjangPerintah)
{
    int pos = findPosition(area, '*', n * m);       // robot starts
    int posFinish = findPosition(area, '$', n * m); // robot ends
    area[pos] = '#';

    for (int i = 0; i < panjangPerintah; i++)
    {
        int backupPos = pos;
        char controller = perintah[i];

        // controller
        if (controller == 'w')
        {
            if (pos - m < 0)
            {
                cout << i << " Robot Menabrak Tembok" << endl;
                pos = backupPos;
                continue;
            }

            pos -= m;
        }
        else if (controller == 'a')
        {
            if (pos % m == 0)
            {
                cout << i << " Robot Menabrak Tembok" << endl;
                pos = backupPos;
                continue;
            }

            pos--;
        }
        else if (controller == 's')
        {
            if (pos + m >= m * n)
            {
                cout << i << " Robot Menabrak Tembok" << endl;
                pos = backupPos;
                continue;
            }

            pos += m;
        }
        else if (controller == 'd')
        {
            if ((pos + 1) % m == 0)
            {
                cout << i << " Robot Menbrak Tembok" << endl;
                pos = backupPos;
                continue;
            }

            pos++;
        }

        // check obstacle
        if (area[pos] == 'o')
        {
            cout << i << " Robot Menabrak Obstacle" << endl;
            pos = backupPos;
            continue;
        }

        area[pos] = '#';
    }

    if (area[pos] == area[posFinish])
        area[posFinish] = '*';

    printArea(area, n, m);

    if (area[pos] == area[posFinish])
    {
        area[posFinish] = '*';
        cout << "Robot Mencapai Finish";
    }
    else
    {
        cout << "Robot Tidak Mencapai Finish";
    }
}

int main(int argc, char const *argv[])
{

    int n, m;
    cin >> n >> m;

    char area[n * m];
    for (int i = 0; i < (n * m); i++)
    {
        cin >> area[i];
    }

    int a;
    cin >> a;

    char b[a];
    for (int i = 0; i < a; i++)
    {
        cin >> b[i];
    }

    cout << endl;

    robotMove(area, b, n, m, a);
    return 0;
}
