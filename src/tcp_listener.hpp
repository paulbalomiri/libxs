/*
    Copyright (c) 2009-2012 250bpm s.r.o.
    Copyright (c) 2007-2010 iMatix Corporation
    Copyright (c) 2007-2011 Other contributors as noted in the AUTHORS file

    This file is part of Crossroads I/O project.

    Crossroads I/O is free software; you can redistribute it and/or modify it
    under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    Crossroads is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __XS_TCP_LISTENER_HPP_INCLUDED__
#define __XS_TCP_LISTENER_HPP_INCLUDED__

#include "fd.hpp"
#include "own.hpp"
#include "stdint.hpp"
#include "io_object.hpp"
#include "address.hpp"

namespace xs
{

    class io_thread_t;
    class socket_base_t;

    class tcp_listener_t : public own_t, public io_object_t
    {
    public:

        tcp_listener_t (xs::io_thread_t *io_thread_,
            xs::socket_base_t *socket_, const options_t &options_);
        ~tcp_listener_t ();

        //  Set address to listen on.
        int set_address (const char *addr_);

    private:

        //  Handlers for incoming commands.
        void process_plug ();
        void process_term (int linger_);

        //  Handlers for I/O events.
        void in_event (fd_t fd_);

        //  Close the listening socket.
        void close ();

        //  Accept the new connection. Returns the file descriptor of the
        //  newly created connection. The function may return retired_fd
        //  if the connection was dropped while waiting in the listen backlog.
        fd_t accept ();

        //  Address to listen on.
        address_t address;

        //  True, if the undelying file for UNIX domain socket exists.
        bool has_file;

        //  Underlying socket.
        fd_t s;

        //  Handle corresponding to the listening socket.
        handle_t handle;

        //  Socket the listerner belongs to.
        xs::socket_base_t *socket;

        tcp_listener_t (const tcp_listener_t&);
        const tcp_listener_t &operator = (const tcp_listener_t&);
    };

}

#endif
