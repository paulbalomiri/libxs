AM_CPPFLAGS = -I$(top_builddir)/include \
              -I$(top_srcdir)/include

LDADD = $(top_builddir)/src/libxs.la

noinst_PROGRAMS = pair_inproc \
                  pair_tcp \
                  reqrep_inproc \
                  reqrep_tcp \
                  hwm \
                  reqrep_device \
                  sub_forward \
                  invalid_rep \
                  msg_flags \
                  reconnect \
                  linger \
                  shutdown_stress \
                  pair_ipc \
                  reqrep_ipc \
                  timeo \
                  max_sockets \
                  emptyctx \
                  polltimeo \
                  wireformat \
                  libzmq21 \
                  resubscribe \
                  survey \
                  shutdown

pair_inproc_SOURCES = pair_inproc.cpp testutil.hpp
pair_tcp_SOURCES = pair_tcp.cpp testutil.hpp
reqrep_inproc_SOURCES = reqrep_inproc.cpp testutil.hpp
reqrep_tcp_SOURCES = reqrep_tcp.cpp testutil.hpp
hwm_SOURCES = hwm.cpp
reqrep_device_SOURCES = reqrep_device.cpp
sub_forward_SOURCES = sub_forward.cpp
invalid_rep_SOURCES = invalid_rep.cpp
msg_flags_SOURCES = msg_flags.cpp
reconnect_SOURCES = reconnect.cpp
linger_SOURCES = linger.cpp
shutdown_stress_SOURCES = shutdown_stress.cpp
pair_ipc_SOURCES = pair_ipc.cpp testutil.hpp
reqrep_ipc_SOURCES = reqrep_ipc.cpp testutil.hpp
timeo_SOURCES = timeo.cpp testutil.hpp
max_sockets_SOURCES = max_sockets.cpp
emptyctx_SOURCES = emptyctx.cpp
polltimeo_SOURCES = polltimeo.cpp testutil.hpp
wireformat_SOURCES = wireformat.cpp
libzmq21_SOURCES = libzmq21.cpp
resubscribe_SOURCES = resubscribe.cpp
survey_SOURCES = survey.cpp
shutdown_SOURCES = shutdown.cpp

TESTS = $(noinst_PROGRAMS)
