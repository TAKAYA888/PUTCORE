#ifndef COMPONENT_PTR_H_
#define COMPONENT_PTR_H_

#include <memory>

class ComponentBase;
using ComponentPtr = std::weak_ptr<ComponentBase>;

#endif // !COMPONENT_PTR_H_