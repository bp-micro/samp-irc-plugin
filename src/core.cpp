/*
 * Copyright (C) 2014 Incognito
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "core.h"

#include <boost/asio.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/thread.hpp>

boost::scoped_ptr<Core> core;

Core::Core() : work(io_service)
{
	boost::system::error_code error;
	boost::thread thread(boost::bind(&boost::asio::io_service::run, &io_service, error));
}