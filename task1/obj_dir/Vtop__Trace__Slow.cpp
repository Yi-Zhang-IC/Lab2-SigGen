// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


//======================

void Vtop::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vtop::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vtop::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vtop::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vtop::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"clk", false,-1);
        tracep->declBit(c+2,"rst", false,-1);
        tracep->declBit(c+3,"en", false,-1);
        tracep->declBus(c+4,"incr", false,-1, 7,0);
        tracep->declBus(c+5,"dout", false,-1, 7,0);
        tracep->declBus(c+7,"top A_WIDTH", false,-1, 31,0);
        tracep->declBus(c+7,"top D_WIDTH", false,-1, 31,0);
        tracep->declBit(c+1,"top clk", false,-1);
        tracep->declBit(c+2,"top rst", false,-1);
        tracep->declBit(c+3,"top en", false,-1);
        tracep->declBus(c+4,"top incr", false,-1, 7,0);
        tracep->declBus(c+5,"top dout", false,-1, 7,0);
        tracep->declBus(c+6,"top address", false,-1, 7,0);
        tracep->declBus(c+7,"top addrCounter WIDTH", false,-1, 31,0);
        tracep->declBit(c+1,"top addrCounter clk", false,-1);
        tracep->declBit(c+2,"top addrCounter rst", false,-1);
        tracep->declBit(c+3,"top addrCounter en", false,-1);
        tracep->declBus(c+4,"top addrCounter incr", false,-1, 7,0);
        tracep->declBus(c+6,"top addrCounter count", false,-1, 7,0);
        tracep->declBus(c+7,"top sineRom ADDRESS_WIDTH", false,-1, 31,0);
        tracep->declBus(c+7,"top sineRom DATA_WIDTH", false,-1, 31,0);
        tracep->declBit(c+1,"top sineRom clk", false,-1);
        tracep->declBus(c+6,"top sineRom addr", false,-1, 7,0);
        tracep->declBus(c+5,"top sineRom dout", false,-1, 7,0);
    }
}

void Vtop::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vtop::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vtop::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->clk));
        tracep->fullBit(oldp+2,(vlTOPp->rst));
        tracep->fullBit(oldp+3,(vlTOPp->en));
        tracep->fullCData(oldp+4,(vlTOPp->incr),8);
        tracep->fullCData(oldp+5,(vlTOPp->dout),8);
        tracep->fullCData(oldp+6,(vlTOPp->top__DOT__address),8);
        tracep->fullIData(oldp+7,(8U),32);
    }
}
