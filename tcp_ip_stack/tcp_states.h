#ifndef __TCP_STATES_H__
#define __TCP_STATES_H__
#include <rte_tcp.h>
#include <rte_ip.h>
//#include "tcp_tcb.h"
struct tcb;

enum TCP_STATE_{
   TCP_STATE_CLOSED,
   LISTENING,
   SYN_SENT,
   SYN_RECV,
   TCP_ESTABLISHED,
   TCP_STATE_FIN_1,
   TCP_FIN_2,
   TCP_STATES,
};

typedef int (tcpinstate)(struct tcb *, struct tcp_hdr*, struct ipv4_hdr *, struct rte_mbuf *);
int tcp_fin1(struct tcb *ptcb, struct tcp_hdr* tcphdr, struct ipv4_hdr *iphdr, struct rte_mbuf *mbuf);
int tcp_fin2(struct tcb *ptcb, struct tcp_hdr* tcphdr, struct ipv4_hdr *iphdr, struct rte_mbuf *mbuf);
int tcp_closed(struct tcb *ptcb, struct tcp_hdr* tcphdr, struct ipv4_hdr *iphdr, struct rte_mbuf *mbuf);
int tcp_syn_sent(struct tcb *ptcb, struct tcp_hdr* ptcphdr, struct ipv4_hdr *iphdr, struct rte_mbuf *mbuf);
int tcp_syn_rcv(struct tcb *ptcb, struct tcp_hdr* ptcphdr, struct ipv4_hdr *iphdr, struct rte_mbuf *mbuf);
int tcp_established(struct tcb *ptcb, struct tcp_hdr* ptcphdr, struct ipv4_hdr *iphdr, struct rte_mbuf *mbuf);
int tcp_listen(struct tcb *ptcb, struct tcp_hdr* ptcphdr, struct ipv4_hdr *iphdr, struct rte_mbuf *mbuf);
int tcp_closed(struct tcb *ptcb, struct tcp_hdr* tcphdr, struct ipv4_hdr *iphdr, struct rte_mbuf *mbuf);


typedef enum TCP_STATE_ TCP_STATE;

extern tcpinstate *tcpswitch[TCP_STATES];
#endif
