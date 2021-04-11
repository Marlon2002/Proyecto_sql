#include <iostream>
#include <windows.h>
#include <mysql.h>
#include <sstream>
#define MAX_NAME_LENGTH 50

using namespace std;

int main()
{

    MYSQL* conn;

    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "root", "MusicaEsVida2002", "db_kardex", 0, NULL, 0);

    if (conn) {
        cout << "Connected...........!";




        cout << endl << endl << endl;
        cout << "Enter which operation you want to perform" << endl;
        cout << "1: Insert" << endl;
        cout << "2: View" << endl;
        cout << "3: Update" << endl;
        cout << "4: Delete" << endl;
        cout << "5: Exit" << endl;
        stringstream ss;
        string idproducto, producto, idmarca, descripcion, precio_costo, precio_venta;
        string q = ss.str();
        const char* query = q.c_str();
        int op;
        cin >> op;
        do {
            switch (op) {
            case 1:


                cout << "Ingrese producto:" << endl;
                getline(cin >> ws, producto);
                cout << "Ingrese id marca:" << endl;
                getline(cin >> ws, idmarca);
                cout << "Ingrese descripcion:" << endl;
                getline(cin >> ws, descripcion);
                cout << "Ingrese precio_costo:" << endl;
                getline(cin >> ws, precio_costo);
                cout << "Ingrese precio_venta:" << endl;
                getline(cin >> ws, precio_venta);


                ss << "insert into productos(producto, idmarca, descripcion, precio_costo, precio_venta) values('" << producto << "', " << idmarca << ", '" << descripcion << "', " << precio_costo << ", " << precio_venta << " )";

                

                if (mysql_query(conn, query) >= 0) {
                    cout << "Insertado";
                }
                else {
                    cout << "Error en la inserción";
                }
                break;

            case 2:
                mysql_query(conn, "SELECT * FROM test");
                MYSQL_ROW row;
                MYSQL_RES* result;
                result = mysql_use_result(conn);
                cout << endl << endl;
                while (row = mysql_fetch_row(result)) {
                    cout << "idProducto: " << row[0] << " producto: " << row[1] << endl;
                }
                break;
            case 3:
                cout << "Ingrese nuevo IdProducto:" << endl;
                getline(cin >> ws, idproducto);
                cout << "Ingrese nuevo producto:" << endl;
                getline(cin >> ws, producto);
                cout << "Ingrese nueva descripcion:" << endl;
                getline(cin >> ws, descripcion);
                cout << "Ingrese nuevo precio_costo:" << endl;
                getline(cin >> ws, precio_costo);
                cout << "Ingrese nuevo precio_venta:" << endl;
                getline(cin >> ws, precio_venta);


                ss << "update test set name=" << idproducto << ",'" << producto << "', '" << descripcion << "', " << precio_costo << "<< precio_venta << " " where id=" << idproducto << "";

                
                mysql_query(conn, query);
                cout << "Datos actualizados" << endl;

                break;


            }
        } while (op != 6);
    }
    else {
        cout << "Not Connected..........!";
    }


    return 0;
}