#include "CenteredCircle.h"
#include "CircleBounds.h"
#include "PhysicsShapeT.h"

namespace sfp {
    class PhysicsCircle : public PhysicsShapeT<CenteredCircle,CircleBounds>
    {
    
    };
}

