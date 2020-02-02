#include <iostream>
#include <capnp/message.h>
#include <capnp/serialize.h>
#include "gen/data.capnp.h"

int main()
{
        capnp::MallocMessageBuilder msg_builder;
        FrameData::Builder frame = msg_builder.initRoot<FrameData>();

        frame.setFrameId(1);
        int size = 1526144;
        uint8_t* addr = (uint8_t*) malloc(size);
        memset(addr, 0, size);

        auto data = capnp::Data::Reader(addr, size);

        frame.setImage(kj::arrayPtr(addr, size));

        auto words = capnp::messageToFlatArray(msg_builder);

        capnp::FlatArrayMessageReader cmsg(words);
        FrameData::Reader frame2 = cmsg.getRoot<FrameData>();
        std::cout << frame2.getFrameId() << std::endl;

	std::cout << "Done" << std::endl;
    return 0;
}
