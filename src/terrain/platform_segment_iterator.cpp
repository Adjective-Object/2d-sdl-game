#include "platform.hpp"
#include "platformsegment.hpp"
#include "platform_segment_iterator.hpp"
#include <iostream>

typedef PlatformSegmentArray::iterator itr;

PlatformSegmentArray::PlatformSegmentArray(const Platform* p) : platform(p) {}

itr PlatformSegmentArray::begin() {
    return itr(PlatformSegment(platform, 0));
}

itr PlatformSegmentArray::end() {
    return itr(PlatformSegment(platform, platform->points.size() - 1));
}

PlatformSegmentArray::iterator::iterator(PlatformSegment s) : segment(s) {}
PlatformSegmentArray::iterator::iterator() {}

itr PlatformSegmentArray::iterator::operator++() {
    segment.index++;
    return *this;
}

itr PlatformSegmentArray::iterator::operator++(int offset) {
    return operator++();
}

PlatformSegment& PlatformSegmentArray::iterator::operator*() {
    return segment;
}

PlatformSegment* PlatformSegmentArray::iterator::operator->() {
    return &segment;
}

bool PlatformSegmentArray::iterator::operator==(itr other) {
    return other.segment == segment;
}

bool PlatformSegmentArray::iterator::operator!=(itr other) {
    return !operator==(other);
}
