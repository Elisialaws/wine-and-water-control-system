#pragma once
#include"struct.h"
void WriteInventory1(Inventory1 *Inventory1head);
void WriteInventory2(Inventory2 *Inventory2head);
void WriteClient(Client *Clienthead);
void WriteTotaldata(Totaldata *Totalhead);
int FindClient(Client* head, char* names, char* phones);
Inventory1 * CreateInventory1();
Inventory2* CreateInventory2();
Client *CreateClent();
Sellinformation * CreateSellInformation();
Totaldata *CreateTotalHead();