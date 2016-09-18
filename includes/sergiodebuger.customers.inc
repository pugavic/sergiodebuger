<?php

function sergiodebuger_add_customers_get(){
    return <<<EOT
    1309*2*300*Privet eto commentariy
    ===========
    1350*4*600*Privet eto commentariy
    ===========
    1350*3*1500*eto opisanie
EOT;
}

function sergiodebuger_add_customers($customers_counts=531) {

    $table_name = "straits_csv_journals";
 $ret = recur(array(sergiodebuger_add_customers_get()),array("@[\s\n]*[=]{3,}[\s\n]*@","@\*@"));
 $data = &$ret[0];
    // Drupal 7, dynamic query
$query = db_insert($table_name);


 $query->fields(array(
    'account',
     'straits_csv_backlog_id',
    'journal_date_yyyymmdd',
    'journal_amount' ,
    'security_description_line_one',
    'identifier',
    'firm',
    'office',
  ));
$i = 0;
foreach ($data as $value) {
    $i++;
  $query->values(array(
    'account' => trim($value[0]),
    'straits_csv_backlog_id' => trim($value[1]),
    'journal_date_yyyymmdd' => time(),
    'journal_amount' => trim($value[2]),
    'security_description_line_one' => trim($value[3]),
    'identifier' => 0,
    'firm' => '',
    'office' => '',
  ));
}

$query->execute();

 // shat("Customeri sozdani $customers_counts shtuk");
  return "Customeri sozdani $i shtuk";
    
}