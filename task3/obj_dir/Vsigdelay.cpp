// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsigdelay.h for the primary calling header

#include "Vsigdelay.h"
#include "Vsigdelay__Syms.h"

//==========

void Vsigdelay::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsigdelay::eval\n"); );
    Vsigdelay__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vsigdelay* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("sigdelay.sv", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vsigdelay::_eval_initial_loop(Vsigdelay__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("sigdelay.sv", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vsigdelay::_sequent__TOP__1(Vsigdelay__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay::_sequent__TOP__1\n"); );
    Vsigdelay* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*7:0*/ __Vdly__sigdelay__DOT__wire1;
    CData/*7:0*/ __Vdlyvdim0__sigdelay__DOT__ram2ports__DOT__ram_array__v0;
    CData/*7:0*/ __Vdlyvval__sigdelay__DOT__ram2ports__DOT__ram_array__v0;
    CData/*0:0*/ __Vdlyvset__sigdelay__DOT__ram2ports__DOT__ram_array__v0;
    // Body
    __Vdly__sigdelay__DOT__wire1 = vlTOPp->sigdelay__DOT__wire1;
    __Vdlyvset__sigdelay__DOT__ram2ports__DOT__ram_array__v0 = 0U;
    if (vlTOPp->rst) {
        __Vdly__sigdelay__DOT__wire1 = 0U;
    } else {
        if (vlTOPp->en) {
            __Vdly__sigdelay__DOT__wire1 = (0xffU & 
                                            ((IData)(vlTOPp->sigdelay__DOT__wire1) 
                                             + (IData)(vlTOPp->incr)));
        }
    }
    if (vlTOPp->rd_en) {
        vlTOPp->delayed_signal = vlTOPp->sigdelay__DOT__ram2ports__DOT__ram_array
            [(0xffU & ((IData)(vlTOPp->sigdelay__DOT__wire1) 
                       - (IData)(vlTOPp->offset)))];
    }
    if (vlTOPp->wr_en) {
        __Vdlyvval__sigdelay__DOT__ram2ports__DOT__ram_array__v0 
            = vlTOPp->mic_signal;
        __Vdlyvset__sigdelay__DOT__ram2ports__DOT__ram_array__v0 = 1U;
        __Vdlyvdim0__sigdelay__DOT__ram2ports__DOT__ram_array__v0 
            = vlTOPp->sigdelay__DOT__wire1;
    }
    vlTOPp->sigdelay__DOT__wire1 = __Vdly__sigdelay__DOT__wire1;
    if (__Vdlyvset__sigdelay__DOT__ram2ports__DOT__ram_array__v0) {
        vlTOPp->sigdelay__DOT__ram2ports__DOT__ram_array[__Vdlyvdim0__sigdelay__DOT__ram2ports__DOT__ram_array__v0] 
            = __Vdlyvval__sigdelay__DOT__ram2ports__DOT__ram_array__v0;
    }
}

void Vsigdelay::_eval(Vsigdelay__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay::_eval\n"); );
    Vsigdelay* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

VL_INLINE_OPT QData Vsigdelay::_change_request(Vsigdelay__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay::_change_request\n"); );
    Vsigdelay* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vsigdelay::_change_request_1(Vsigdelay__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay::_change_request_1\n"); );
    Vsigdelay* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vsigdelay::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((en & 0xfeU))) {
        Verilated::overWidthError("en");}
    if (VL_UNLIKELY((rd_en & 0xfeU))) {
        Verilated::overWidthError("rd_en");}
    if (VL_UNLIKELY((wr_en & 0xfeU))) {
        Verilated::overWidthError("wr_en");}
}
#endif  // VL_DEBUG
