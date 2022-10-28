// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vsigdelay__Syms.h"


//======================

void Vsigdelay::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vsigdelay::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vsigdelay__Syms* __restrict vlSymsp = static_cast<Vsigdelay__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vsigdelay::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vsigdelay::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vsigdelay__Syms* __restrict vlSymsp = static_cast<Vsigdelay__Syms*>(userp);
    Vsigdelay* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vsigdelay::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vsigdelay__Syms* __restrict vlSymsp = static_cast<Vsigdelay__Syms*>(userp);
    Vsigdelay* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"clk", false,-1);
        tracep->declBit(c+2,"rst", false,-1);
        tracep->declBit(c+3,"en", false,-1);
        tracep->declBit(c+4,"rd_en", false,-1);
        tracep->declBit(c+5,"wr_en", false,-1);
        tracep->declBus(c+6,"incr", false,-1, 7,0);
        tracep->declBus(c+7,"offset", false,-1, 7,0);
        tracep->declBus(c+8,"mic_signal", false,-1, 7,0);
        tracep->declBus(c+9,"delayed_signal", false,-1, 7,0);
        tracep->declBus(c+12,"sigdelay A_WIDTH", false,-1, 31,0);
        tracep->declBus(c+12,"sigdelay D_WIDTH", false,-1, 31,0);
        tracep->declBit(c+1,"sigdelay clk", false,-1);
        tracep->declBit(c+2,"sigdelay rst", false,-1);
        tracep->declBit(c+3,"sigdelay en", false,-1);
        tracep->declBit(c+4,"sigdelay rd_en", false,-1);
        tracep->declBit(c+5,"sigdelay wr_en", false,-1);
        tracep->declBus(c+6,"sigdelay incr", false,-1, 7,0);
        tracep->declBus(c+7,"sigdelay offset", false,-1, 7,0);
        tracep->declBus(c+8,"sigdelay mic_signal", false,-1, 7,0);
        tracep->declBus(c+9,"sigdelay delayed_signal", false,-1, 7,0);
        tracep->declBus(c+10,"sigdelay wire1", false,-1, 7,0);
        tracep->declBus(c+11,"sigdelay wire2", false,-1, 7,0);
        tracep->declBus(c+12,"sigdelay addrCounter WIDTH", false,-1, 31,0);
        tracep->declBit(c+1,"sigdelay addrCounter clk", false,-1);
        tracep->declBit(c+2,"sigdelay addrCounter rst", false,-1);
        tracep->declBit(c+3,"sigdelay addrCounter en", false,-1);
        tracep->declBus(c+6,"sigdelay addrCounter incr", false,-1, 7,0);
        tracep->declBus(c+10,"sigdelay addrCounter count", false,-1, 7,0);
        tracep->declBus(c+12,"sigdelay adder WIDTH", false,-1, 31,0);
        tracep->declBus(c+10,"sigdelay adder a", false,-1, 7,0);
        tracep->declBus(c+7,"sigdelay adder b", false,-1, 7,0);
        tracep->declBus(c+11,"sigdelay adder sum", false,-1, 7,0);
        tracep->declBus(c+12,"sigdelay ram2ports ADDRESS_WIDTH", false,-1, 31,0);
        tracep->declBus(c+12,"sigdelay ram2ports DATA_WIDTH", false,-1, 31,0);
        tracep->declBit(c+1,"sigdelay ram2ports clk", false,-1);
        tracep->declBit(c+5,"sigdelay ram2ports wr_en", false,-1);
        tracep->declBit(c+4,"sigdelay ram2ports rd_en", false,-1);
        tracep->declBus(c+10,"sigdelay ram2ports wr_addr", false,-1, 7,0);
        tracep->declBus(c+11,"sigdelay ram2ports rd_addr", false,-1, 7,0);
        tracep->declBus(c+8,"sigdelay ram2ports din", false,-1, 7,0);
        tracep->declBus(c+9,"sigdelay ram2ports dout", false,-1, 7,0);
    }
}

void Vsigdelay::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vsigdelay::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vsigdelay__Syms* __restrict vlSymsp = static_cast<Vsigdelay__Syms*>(userp);
    Vsigdelay* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vsigdelay::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vsigdelay__Syms* __restrict vlSymsp = static_cast<Vsigdelay__Syms*>(userp);
    Vsigdelay* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->clk));
        tracep->fullBit(oldp+2,(vlTOPp->rst));
        tracep->fullBit(oldp+3,(vlTOPp->en));
        tracep->fullBit(oldp+4,(vlTOPp->rd_en));
        tracep->fullBit(oldp+5,(vlTOPp->wr_en));
        tracep->fullCData(oldp+6,(vlTOPp->incr),8);
        tracep->fullCData(oldp+7,(vlTOPp->offset),8);
        tracep->fullCData(oldp+8,(vlTOPp->mic_signal),8);
        tracep->fullCData(oldp+9,(vlTOPp->delayed_signal),8);
        tracep->fullCData(oldp+10,(vlTOPp->sigdelay__DOT__wire1),8);
        tracep->fullCData(oldp+11,((0xffU & ((IData)(vlTOPp->sigdelay__DOT__wire1) 
                                             - (IData)(vlTOPp->offset)))),8);
        tracep->fullIData(oldp+12,(8U),32);
    }
}
