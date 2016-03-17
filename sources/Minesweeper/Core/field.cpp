#include "field.h"

Field::Field()
{

}

Field::Field(int difficulty)
{
 //   switch (difficulty) {
  //  case 1:
        field = new Cell* [FIELD_SETTING_SIZE * difficulty];
                for (int i = 0; i < FIELD_SETTING_SIZE * difficulty; i++)
                {
                  field[i] = new Cell [FIELD_SETTING_SIZE * difficulty];
                }
  //      break;
 //    default:
 //       break;
 //   }
}
