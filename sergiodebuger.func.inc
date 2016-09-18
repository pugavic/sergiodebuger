<?php

error_reporting(E_ALL);
ini_set('display_errors', TRUE);
/**
 * Helper for debug
 * @param mixed $message
 * @param string $type
 */
function shat($message=null,$type = 'status') {
  drupal_set_message('<pre>'.var_export($message, TRUE).'</pre>',$type);
}

/**
 * Helper for debug
 * @param string $type
 */
function trc($type = 'status') {
  shat(debug_backtrace(),$type);
}



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
