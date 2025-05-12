#pragma once

namespace RE
{
    namespace BSResource::Archive2
    {
        class DataReader
        {
        public:
            class DataLoader
            {
            public:
                // members
                MemoryManager::AutoScrapBuffer buffer;           // 00
                BSTSmartPointer<Stream>        stream;           // 08
                std::uint64_t                  initialPosition;  // 10
                std::uint64_t                  position;         // 18
                std::uint64_t                  ioBufferPos;      // 20
                std::uint64_t                  ioBufferEnd;      // 28
            };
            static_assert(sizeof(DataLoader) == 0x30);

            class StringLoader :
                public DataLoader  // 000
            {
            public:
                char          currentString[260];   // 030
                std::uint32_t totalStrings;         // 134
                std::uint32_t nextStringIndex;      // 138
                std::uint16_t currentStringLength;  // 13C
            };
            static_assert(sizeof(StringLoader) == 0x140);

            // members
            BSTSmartPointer<Stream> stream;        // 00
            DataLoader*             dataLoader;    // 08
            StringLoader*           stringLoader;  // 10
            std::uint32_t           totalFiles;    // 18
        };
        static_assert(sizeof(DataReader) == 0x20);
    }
}
