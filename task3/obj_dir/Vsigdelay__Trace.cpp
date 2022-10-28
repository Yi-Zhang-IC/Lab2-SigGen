// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vsigdelay__Syms.h"


void Vsigdelay::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vsigdelay__Syms* __restrict vlSymsp = static_cast<Vsigdelay__Syms*>(userp);
    Vsigdelay* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vsigdelay::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vsigdelay__Syms* __restrict vlSymsp = static_cast<Vsigdelay__Syms*>(userp);
    Vsigdelay* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgBit(oldp+0,(vlTOPp->clk));
        tracep->chgBit(oldp+1,(vlTOPp->rst));
        tracep->chgBit(oldp+2,(vlTOPp->en));
        tracep->chgBit(oldp+3,(vlTOPp->rd_en));
        tracep->chgBit(oldp+4,(vlTOPp->wr_en));
        tracep->chgCData(oldp+5,(vlTOPp->incr),8);
        tracep->chgCData(oldp+6,(vlTOPp->offset),8);
        tracep->chgCData(oldp+7,(vlTOPp->mic_signal),8);
        tracep->chgCData(oldp+8,(vlTOPp->delayed_signal),8);
        tracep->chgCData(oldp+9,(vlTOPp->sigdelay__DOT__wire1),8);
        tracep->chgCData(oldp+10,((0xffU & ((IData)(vlTOPp->sigdelay__DOT__wire1) 
                                            - (IData)(vlTOPp->offset)))),8);
    }
}

void Vsigdelay::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vsigdelay__Syms* __restrict vlSymsp = static_cast<Vsigdelay__Syms*>(userp);
    Vsigdelay* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
    }
}
