<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

function recur($arr_data = array(), $reg_exp) {
    $new_ret = $arr_data;

    $new_reg = $reg_exp;
    $curr_reg = array_shift($new_reg);
    foreach ($new_ret as &$new_ret_v) {
        $arr = preg_split($curr_reg, $new_ret_v);
        if (count($arr)) {


            if (count($new_reg)) {
                $new_ret_v = recur($arr, $new_reg);
            } else {
                $new_ret_v = $arr;
            }
        } else {
            $new_ret_v = array($new_ret_v);
        }
    }

    return $new_ret;
}
