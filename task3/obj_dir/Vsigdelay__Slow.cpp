// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsigdelay.h for the primary calling header

#include "Vsigdelay.h"
#include "Vsigdelay__Syms.h"

//==========

VL_CTOR_IMP(Vsigdelay) {
    Vsigdelay__Syms* __restrict vlSymsp = __VlSymsp = new Vsigdelay__Syms(this, name());
    Vsigdelay* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vsigdelay::__Vconfigure(Vsigdelay__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vsigdelay::~Vsigdelay() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vsigdelay::_eval_initial(Vsigdelay__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay::_eval_initial\n"); );
    Vsigdelay* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vsigdelay::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay::final\n"); );
    // Variables
    Vsigdelay__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vsigdelay* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vsigdelay::_eval_settle(Vsigdelay__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay::_eval_settle\n"); );
    Vsigdelay* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vsigdelay::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    rst = VL_RAND_RESET_I(1);
    en = VL_RAND_RESET_I(1);
    rd_en = VL_RAND_RESET_I(1);
    wr_en = VL_RAND_RESET_I(1);
    incr = VL_RAND_RESET_I(8);
    offset = VL_RAND_RESET_I(8);
    mic_signal = VL_RAND_RESET_I(8);
    delayed_signal = VL_RAND_RESET_I(8);
    sigdelay__DOT__wire1 = VL_RAND_RESET_I(8);
    { int __Vi0=0; for (; __Vi0<256; ++__Vi0) {
            sigdelay__DOT__ram2ports__DOT__ram_array[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<1; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
