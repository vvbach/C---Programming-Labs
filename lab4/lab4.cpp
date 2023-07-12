#include <iostream>
#include "parallelogram.h"
#include "ellipse.h"
#include <vector>

using namespace std;

int main()
{
    vector<IFigure *> figure;
    int input;
    while (true)
    {
        cout << "Option: " << endl;
        cout << "0) Esc " << endl;
        cout << "1) Add a parallelogram" << endl;
        cout << "2) Add a Ellipse" << endl;
        cout << "3) Calculate the total area of all figures" << endl;
        cout << "4) Calculate the total perimeter of all figures" << endl;
        cout << "5) Calculate the mass center of all figures" << endl;
        cout << "6) Calculate the total memomy of all figures" << endl;
        cout << "7) Draw all figures" << endl;
        cout << "8) Sort figures among themselves by weight" << endl;
        cout << "Choice: ";
        cin >> input;
        if (input == 0)
        {
            break;
        }
        else if (input == 1)
        {
            IFigure *f = new Parallelogram();
            f->initFromDialog();
            figure.push_back(f);
        }
        else if (input == 2)
        {
            IFigure *f = new Ellipse();
            f->initFromDialog();
            figure.push_back(f);
        }
        else if (input == 3)
        {
            double area = 0;
            for (auto f : figure)
            {
                area += f->square();
            }
            cout << "Total area: " << area << endl;
        }
        else if (input == 4)
        {
            double p = 0;
            for (auto f : figure)
            {
                p += f->perimeter();
            }
            cout << "Total perimeter: " << p << endl;
        }
        else if (input == 5)
        {
            CVector2D c;
            double mass_sum = 0;
            for (auto f : figure)
            {
                c.x += f->position().x * f->mass();
                c.y += f->position().y * f->mass();
                mass_sum += f->mass();
            }
            c.x /= mass_sum;
            c.y /= mass_sum;
            cout << "Center: " << c.x << " " << c.y << endl;
        }
        else if (input == 6)
        {
            int total_size = 0;
            for (auto f : figure)
            {
                total_size += f->size();
            }
            cout << "Size: " << total_size << endl;
        }
        else if (input == 7)
        {
            for (auto f : figure)
            {
                f->draw();
            }
        }
        else if (input == 8)
        {
            for (int i = 0; i < figure.size() - 1; i++)
            {
                for (int j = 0; j < figure.size() - i - 1; j++)
                {
                    if (*figure[j + 1] < *figure[j])
                    {
                        IFigure *temp = figure[j];
                        figure[j] = figure[j + 1];
                        figure[j + 1] = temp;
                        delete temp;
                    }
                }
            }
        }
        else
        {
            cout << "Inappropiate input !" << endl;
        }
    }
}
