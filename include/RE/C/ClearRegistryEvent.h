#pragma once

namespace RE
{
    namespace BSResource::Archive2
    {
        struct ClearRegistryEvent
        {
        public:
        };
        static_assert(std::is_empty_v<ClearRegistryEvent>);
    }
}
