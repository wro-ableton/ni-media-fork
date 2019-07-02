//
// Copyright (c) 2017-2019 Native Instruments GmbH, Berlin
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//

#pragma once

#include <ni/media/audio/os/os_source.h>

#include <boost/iostreams/device/file_descriptor.hpp>

#include <boost/filesystem/path.hpp>

class mp4_file_source : public os_source<boost::iostreams::file_descriptor_source>
{
    using base_type = os_source<boost::iostreams::file_descriptor_source>;

public:
    explicit mp4_file_source( const std::string& path, size_t stream = 0 )
    : base_type(
        boost::iostreams::file_descriptor_source( boost::filesystem::path( path ), BOOST_IOS::binary | BOOST_IOS::in ),
        audio::ifstream_info::container_type::mp4,
        stream )
    {
    }
};