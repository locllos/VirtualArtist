#include "field.h"
#include "graphic.h"
#include "list.hpp"

class AbstractFrame
{
protected:
    

    AbstractFrame* parent;
    List<AbstractFrame*> subframes_;
    
public:

    AbstractFrame()  = default;
    ~AbstractFrame() = default;
    
};