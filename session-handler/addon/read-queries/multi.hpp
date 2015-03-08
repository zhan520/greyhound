#pragma once

#include "read-queries/base.hpp"
#include "tree/sleepy-tree.hpp"

namespace entwine
{
    class Schema;
}

class MultiReadQuery : public ReadQuery
{
public:
    MultiReadQuery(
            const entwine::Schema& schema,
            bool compress,
            bool rasterize,
            std::shared_ptr<SleepyTree> sleepyTree,
            MultiResults multiResults);

    virtual bool eof() const;

    virtual std::size_t numPoints() const;

private:
    std::shared_ptr<SleepyTree> m_sleepyTree;
    MultiResults m_multiResults;
    std::size_t m_offset;

    virtual void readPoint(
            uint8_t* pos,
            const entwine::Schema& schema,
            bool rasterize) const;
};

