#include "Agent.hpp"
#include "SuperAgent.hpp"

int main() {
    SuperAgent agentX;
    Agent& agentY = agentX;

    agentX.setID(9999);
    agentY.setID(1337);

    agentX.print();
    return 0;
}
