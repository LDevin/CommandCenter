#include "cache.h"

Cache* Cache::_cache = Q_NULLPTR;

Cache* Cache::cache()
{
    if (Q_NULLPTR == _cache) {
        _cache = new Cache();
    }
    return _cache;
}

Cache::Cache()
{

}

Cache::~Cache()
{

}
