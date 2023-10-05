#include "node.hpp"
#include <string>
using namespace std;
node :: node(string veri ) //düğüm tutma
{
    before=0;
    this -> veri=veri;
    after=0;
} 