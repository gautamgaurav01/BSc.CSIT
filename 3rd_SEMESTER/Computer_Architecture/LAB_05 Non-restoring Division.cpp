//LAB_05 Non-restoring Division
#include <iostream>
using namespace std;

int a[5] = {0, 0, 0, 0, 0};
int q[4] = {0, 0, 0, 0};
int b[5] = {0, 0, 0, 0, 0};
int b2c[5] = {0, 0, 0, 0, 0};

void comp()
{
    int i = 4;
    while (i >= 0 && b[i] != 1)
    {
        b2c[i] = b[i];
        i--;
    }
    while (i >= 0)
    {
        b2c[i] = (b[i] + 1) % 2;
        i--;
    }
    cout << "\n\tB's complement:";
    for (i = 0; i < 5; i++)
    {
        cout << b2c[i];
    }
    cout << endl;
}

void nonresdiv()
{
    for (int i = 0; i < 4; i++)
    {
        if (a[0] == 0)
        {
            int temp = a[4];
            for (int j = 4; j > 0; j--)
            {
                a[j] = a[j - 1];
            }
            a[0] = q[3];
            for (int j = 3; j > 0; j--)
            {
                q[j] = q[j - 1];
            }
            q[0] = 0;
            for (int j = 0; j < 5; j++)
            {
                int sum = a[j] + b2c[j] + 0;
                a[j] = sum % 2;
            }
        }
        else
        {
            int temp = a[4];
            for (int j = 4; j > 0; j--)
            {
                a[j] = a[j - 1];
            }
            a[0] = q[3];
            for (int j = 3; j > 0; j--)
            {
                q[j] = q[j - 1];
            }
            q[0] = 1;
            for (int j = 0; j < 5; j++)
            {
                int sum = a[j] + b[j] + 0;
                a[j] = sum % 2;
            }
        }
    }
}

int main()
{
    cout << "\t\t******NON-RESTORING DIVISION******\n\n";
    cout << "Enter dividend in binary form (4 bits):\n ";
    for (int i = 0; i < 4; i++)
    {
        cin >> q[i];
    }

    cout << "Enter divisor in binary form (5 bits):\n ";
    for (int i = 0; i < 5; i++)
    {
        cin >> b[i];
    }

    comp();

    cout << "\n\t[A]\t[M]\n";
    for (int i = 0; i < 4; i++)
    {
        nonresdiv();
        cout << "\t";
        for (int j = 0; j < 5; j++)
        {
            cout << a[j];
        }
        cout << "\t";
        for (int k = 0; k < 4; k++)
        {
            cout << q[k];
        }
        cout << endl;
    }

    if (a[0] == 1)
    {
        for (int i = 0; i < 5; i++)
        {
            int sum = a[i] + b2c[i] + 0;
            a[i] = sum % 2;
        }
    }

    cout << "\t";
    for (int j = 0; j < 5; j++)
    {
        cout << a[j];
    }

    cout << "\t";
    for (int k = 0; k < 4; k++)
    {
        cout << q[k];
    }
    cout << endl;

    return 0;
}